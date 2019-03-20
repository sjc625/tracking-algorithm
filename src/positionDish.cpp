/*
   Dish Positioner
   USB to Serial
   This code was produced as part of the UMass Lowell
   SPACEHAUC project. It is open for use/modificaton by anyone
   for any purpose.
   */

#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <fcntl.h>
#include <termios.h>
#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include <string>
#include <exception>
#include "../include/positionDish.h"

// Initialize communcation with the positioner
// Returns the device/file stream
// Current antenna position request
/*int P(int stream)
  {
  char inbuff[50];

  int count = read(stream, (void*) inbuff, 14);

  if (count < 0)
  {
  perror("Error reading positioner\n");
  return 1;
  }

  printf("Position: %s\n", inbuff);
  return 0;
  }
  */

// Change antenna elevation
// TODO make port configurable via argv
Patch::Patch( std::string inputPort ) : inputPort_( inputPort ) {
   int stream = open( inputPort_.c_str(), O_RDWR | O_NOCTTY | O_NDELAY );

   if (stream < 0) {
      throw std::runtime_error( "Unable to open UART" );
   }
   struct termios options;
   tcgetattr(stream_, &options);
   options.c_cflag = B2400 | CS8 | CLOCAL | CREAD;
   options.c_iflag = IGNPAR;
   options.c_oflag = 0;
   options.c_lflag = 0;
   tcflush(stream_, TCIFLUSH);
   tcsetattr(stream_, TCSANOW, &options);
}

const int Patch::operator()( int degrees ) {
   int i = 0;
   char cmd[] = {HEX_P, HEX_A, HEX_SPACE, 0, 0, 0, 0};
   int temp;
   char tempo;
   int hex = 0x30;
   if (degrees > 100) {
      i = 1;
      cmd[3] = 0x31;
      degrees = degrees - 100;
   }
   temp = (degrees / 10);
   cmd[i + 3] = to_Hex(temp);
   i++;
   temp = (degrees % 10);
   cmd[i + 3] = to_Hex(temp);
   i++;
   cmd[i + 3] = HEX_CR;
   for (i = 0; i < 6; i++) {
      std::cout << "0x" << std::hex << (int)cmd[i] << std::endl;
   }
   int count = write(stream_, cmd, i + 4);
   if (count < 0)
   {
      perror("Error writing to positioner");
      return 1;
   }

   return 0;
}

Patch::~Patch() {
   close( stream_ );
}

char to_Hex(int integer) {
   switch(integer) {
      case 0: return 0x30;
      case 1: return 0x31;
      case 2: return 0x32;
      case 3: return 0x33;
      case 4: return 0x34;
      case 5: return 0x35;
      case 6: return 0x36;
      case 7: return 0x37;
      case 8: return 0x38;
      case 9: return 0x39;
      default: std::cout << "error, exiting.";
               exit(1);
   }
   return 0;
}
