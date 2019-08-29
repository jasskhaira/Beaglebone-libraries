/*
 * Uart.h
 *
 *  Created on: Aug 29, 2019
 *      Author: root
 */

#ifndef UART_H_
#define UART_H_


#include<iostream>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<termios.h>   // using the termios.h library
#include<string.h>
#include <vector>
#include<string.h>
using namespace std;

#define UART00 "/dev/ttyO0"
#define UART01 "/dev/ttyO1"
#define UART02 "/dev/ttyO2"
#define UART03 "/dev/ttyO3"
#define UART04 "/dev/ttyO4"


class Uart
{

public:

//----------------------Api is used to initate the uart port----------------------
 int Init(char port[],int baudrate);

 //---------Api is used to send data-----------------------------
 int send(char data[]);

 //-----------Api is used to recieve data-----------------------------
  int recieve(char *receive);
  int recieve(char receive[],int length);
private:
 int file, count;
 unsigned char receivebuff[0];
 };

#endif /* UART_H_ */




