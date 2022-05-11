/*
 * debug_serial.h
 *
 * Created: 2022-05-10
 *  Author: Adithya Yuri
 */ 


#ifndef DEBUG_SERIAL_H_
#define DEBUG_SERIAL_H_

#include <asf.h>

struct usart_module usart_instance;

#define SERCOM_STDIO	SERCOM3
#define SERCOM_MUX		USART_RX_1_TX_0_XCK_1
#define SERCOM_PAD0		PINMUX_PA22C_SERCOM3_PAD0
#define SERCOM_PAD1		PINMUX_PA23C_SERCOM3_PAD1
#define SERCOM_PAD2		PINMUX_UNUSED
#define SERCOM_PAD3		PINMUX_UNUSED
#define SERCOM_BAUD		115200

void setupStdioSerial(void);

#endif /* DEBUG_SERIAL_H_ */