//============================================================================
// Name        : Usart.cpp
// Author      : Jaspreet Singh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Uart.h"



//----------------------Api is used to initate the uart port----------------------


 int Uart::Init(char port[],int baudrate)
 	 {
	 	 switch(baudrate){

	 	 	 case 1200:
	 	 		baudrate=B1200;
	 	 		break;

	 	 	 case 1800:
	 	 	 	baudrate=B1800;
	 	 	 	break;


	 	 	 case 2400:
	 	 	 	baudrate=B2400;
	 	 	 	break;

	 	 	 case 4800:
	 	 	 	baudrate=B4800;
	 	 	 	break;

	 	 	 case 9600:
	 	 	 	baudrate=B9600;
	 	 	 	break;

	 	 	 case 19200:
	 	 	 	baudrate=B19200;
	 	 	 	break;

	 	 	 case 38400:
	 	 	 	baudrate=B38400;
	 	 	 	break;

	 	 	 case 57600:
	 	 	 	baudrate=B57600;
	 	 	 	break;

	 	 	 case 115200:
	 	 	 	baudrate=B115200;
	 	 	 	break;

	 	 	 case 230400:
	 	 	 	baudrate=B230400;
	 	 	 	break;

	 	 	 case 460800:
	 	 	 	baudrate=B460800;
	 	 	 	break;

	 	 	 case 500000:
	 	 	 	baudrate=B500000;
	 	 	 	break;

	 	 	 case 576000:
	 	 	 	baudrate=B576000;
	 	 	 	break;

	 	 	 case 921600:
	 	 	 	baudrate=B921600;
	 	 	 	break;

	 	 	 case 1000000:
	 	 	 	baudrate=B1000000;
	 	 	 	break;

	 	 	 case 1152000:
	 	 	 	baudrate=B1152000;
	 	 	 	break;

	 	 	 case 1500000:
	 	 	 	baudrate=B1500000;
	 	 	 	break;

	 	 	 case 2000000:
	 	 	 	baudrate=B2000000;
	 	 	 	break;

	 	 	 case 2500000:
	 	 	 	baudrate=B2500000;
	 	 	 	break;


	 	 	 case 3000000:
	 	 	 	baudrate=B3000000;
	 	 	 	break;

	 	 	 case 350000:
	 	 	 	baudrate=B3500000;
	 	 	 	break;

	 	 	 case 4000000:
	 	 	 	baudrate=B4000000;
	 	 	 	break;

	 	 	 default:
	 	 		 printf("Choose Correct Baudrate\n");


	 	 }
		  if ((file =open(port, O_RDWR | O_NOCTTY | O_NDELAY))<0)
		  {
		  perror("UART: Failed to open the file.\n");
		  return -1;
		  }



	   struct termios options;               //The termios structure is vital
	   tcgetattr(file, &options);            //Sets the parameters associated with file

	   // Set up the communications options:
	   //   9600 baud, 8-bit, enable receiver, no modem control lines
	   options.c_cflag = baudrate | CS8 | CREAD | CLOCAL;
	   options.c_iflag = IGNPAR | ICRNL;    //ignore partity errors, CR -> newline
	   tcflush(file, TCIFLUSH);             //discard file information not transmitted
	   tcsetattr(file, TCSANOW, &options);  //changes occur immmediately
	   return 1;
   }


 //---------Api is used to send data-----------------------------

 int Uart::send(char data[])
 	 {
	 	 printf("%d",strlen(data));
	 	 if ((count = write(file,data,strlen(data)))<0)
	 	 {
	       perror("Failed to write to the output\n");
	       return -1;
	    }
	 	 return 1;
 	 }



 /*-----------Api is used to recieve data-----------------------------
	it return 1 on success and return 0 in when there is no data available
	it only receive one character

*/
 int Uart::recieve(char *receive)
  	  {
	   if ((count = read(file, receivebuff, 2))<0){   //receive the data
	      perror("Failed to read from the input\n");
	      return -1;
	   }
	   if (count>0)
	   {
		   *receive=receivebuff[0];
		   return 1;

	   }
	   else
	   {
		   return 0;
	   }
  	  }


 /* It is used to receive the stream of data
  * it return -1 on failure and return 1 on success
  */

 int Uart::recieve(char receive[],int length)
  	  {
	   if ((count = read(file, (void*)receive,length))<0){   //receive the data
	      perror("Failed to read from the input\n");
	      return -1;
	   }
	   else
	   {
	   return 1;
	   }
  	  }
