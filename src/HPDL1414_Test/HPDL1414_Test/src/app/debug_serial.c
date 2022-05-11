/*
 * debug_serial.c
 *
 * Created: 2022-05-10
 *  Author: Adithya Yuri
 */ 

#include "app/debug_serial.h"

 void setupStdioSerial()
 {
	 struct usart_config config_usart;
	 usart_get_config_defaults(&config_usart);

	 config_usart.baudrate    = SERCOM_BAUD;
	 config_usart.mux_setting = SERCOM_MUX;
	 config_usart.pinmux_pad0 = SERCOM_PAD0;
	 config_usart.pinmux_pad1 = SERCOM_PAD1;
	 config_usart.pinmux_pad2 = SERCOM_PAD2;
	 config_usart.pinmux_pad3 = SERCOM_PAD3;

	 usart_init(&usart_instance, SERCOM_STDIO, &config_usart);

	 stdio_serial_init(&usart_instance, SERCOM_STDIO, &config_usart);
	 usart_enable(&usart_instance);
 }