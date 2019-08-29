/*
 * Example.cpp
 *
 *  Created on: Aug 29, 2019
 *      Author: root
 */

/* This example demonstrate how to use UART library
 * connect beaglebone with Arduino on uart 04 port
 */


#include"Uart.h"

Uart BBuart;

int main()
{
	char recv[100];

	BBuart.Init(UART04,9600);

	BBuart.send("Hello");

	usleep(10000);

	BBuart.recieve(recv,100);
	printf("data is %s\n",recv);



	return 1;


}

