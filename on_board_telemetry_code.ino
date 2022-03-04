// The following code is executed on the telemetry board of the race car.

#include <CAN.h>
#include <SPI.h>
#include <SoftwareSerial.h>

#define BUS_SPEED 500

void setup() {
  Serial.begin(19200);//14400,19200,28800,38400,57600,115200
  //delay(10);

  CAN.begin();
  CAN.baudConfig(BUS_SPEED);
  CAN.setMode(LISTEN);
  //delay(200); // Wait for the Can Bus to empty in case there is an ongoing data transfer.
}

void loop() {
  byte length, rx_status;
  
  unsigned short frame_id;
  byte frame_data[8];
  byte frame_id_bytes[2];
  
  // clear receive buffers (if need be)
  frame_data[0] = 0x00;
  frame_data[1] = 0x00;
  frame_data[2] = 0x00;
  frame_data[3] = 0x00;
  frame_data[4] = 0x00;
  frame_data[5] = 0x00;
  frame_data[6] = 0x00;
  frame_data[7] = 0x00;

  frame_id = 0x0;
  length = 0;

  rx_status = CAN.readStatus();
  if ((rx_status & 0x01) == 0x01){ // if the LSB of rx_status is set to 1, read buffer 0
      CAN.readDATA_ff_0(&length, frame_data, &frame_id);  
    }
  else if ((rx_status & 0x02) == 0x02){ // if the 2nd LSB of rx_status is set to 1, read buffer 1
      CAN.readDATA_ff_1(&length, frame_data, &frame_id);
  }

  // extract the data from the CAN frame, if available
  // and send them directly to the serial antenna
  if (((rx_status & 0x01) == 0x01) || ((rx_status & 0x02) == 0x02)){
    if(frame_id == 0x5f0 || frame_id == 0x5f1 || frame_id == 0x5f2 || frame_id == 0x5f3 || frame_id == 0x5f4 || frame_id == 0x5f5 || frame_id == 0x5f6 || frame_id == 0x5f7){
      // Send the header of the message
      Serial.write('~');
      delay(3);
      // The frame id's are universal, therefore we can send it as it is
      // Since the frame id is an unsigned short, but the telemetry software is expecting to read an unsigned int,
      // we can either change the telemetry software accordingly or just type cast the frame id
      // to an unsigned int.
      //int2Bytes(frame_id, frame_id_bytes);
      //Serial.write(frame_id_bytes[0]);
      //Serial.write(frame_id_bytes[1]);
      Serial.write(highByte(frame_id)); // Both ways work well.
      delay(3);
      Serial.write(lowByte(frame_id));
      delay(3);
      // Send the data frame. High byte first, low byte second for each of the four variables.
      for (int i=0;i<8;i++){
        Serial.write(frame_data[i]);
        delay(3);
      }
      // Send the footer of the message
      Serial.write('.');
      delay(3);
      Serial.write('\n');
      delay(3);
      Serial.flush();
    }
  }
}


// Will see if necessary, since we don't convert the data before sending them wirelessly
void int2Bytes(unsigned short val,byte* bytes_array){
  // Create union of shared memory space
  union {
    unsigned short int_variable;
    byte temp_array[2];
  } u;
  // Overwrite bytes of union with int variable
  u.int_variable = val;
  // Assign bytes to input array
  memcpy(bytes_array, u.temp_array, 2);
}
