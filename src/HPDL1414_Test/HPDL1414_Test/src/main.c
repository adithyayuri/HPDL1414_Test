/**
 * \file main.c
 *
 * \brief 
 *
 * Created: 2022-05-10 9:14:04 PM
 *  Author: Adithya Yuri 
 */

#include <asf.h>
#include "app/debug_serial.h"
#include "app/sn74hc595_driver.h"

#define BUF_LENGTH 16

static uint8_t buffer[BUF_LENGTH] = {
	0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,
	0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F
};

int main (void)
{
	system_init();
	// Setup debug serial in SERCOM3
	setupStdioSerial();
	// Setup 74HC595 SPI
	conf_spi_master();
	
	while (1) {
		printf("Hello World\n\r");
		for (int i=0; i<200000; i++);
		spi_write_buffer_wait(&spi_instance_sn74hc595, buffer, BUF_LENGTH);
	}
}
