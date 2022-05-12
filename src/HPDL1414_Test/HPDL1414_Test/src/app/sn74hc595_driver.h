/*
 * sn74hc595_driver.h
 *
 * Created: 2022-05-10
 *  Author: Adithya Yuri
 */ 


#ifndef SN74HC595_DRIVER_H_
#define SN74HC595_DRIVER_H_

#include <asf.h>

/*
 * SERCOM SPI
 * 
 * Serial CLK - PA07
 * Serial OUT - PA06
 */ 
#define SN74HC595_SPI_MODULE  EXT1_SPI_MODULE
#define SN74HC595_MUX_SETTING EXT1_SPI_SERCOM_MUX_SETTING 
#define SN74HC595_PINMUX_PAD0 PINMUX_UNUSED // PA04
#define SN74HC595_PINMUX_PAD1 PINMUX_UNUSED // PA05
#define SN74HC595_PINMUX_PAD2 EXT1_SPI_SERCOM_PINMUX_PAD2 // PA06
#define SN74HC595_PINMUX_PAD3 EXT1_SPI_SERCOM_PINMUX_PAD3 // PA07
#define SN74HC595_BUAD		  1000000

/*
 * GPIO 
 * 
 * Output Enable (Active LOW)- PB00
 * Latch - PB01
 * MASTER Clear (Active LOW) - PB02
 */ 
#define SN74HC595_OUTEN		PIN_PB00
#define SN74HC595_LATCH		PIN_PB01
#define SN74HC595_CLEAR		PIN_PB02

#define SN74HC595_OUTEN_HIGH   port_pin_set_output_level(SN74HC595_OUTEN, true)
#define SN74HC595_OUTEN_LOW    port_pin_set_output_level(SN74HC595_OUTEN, false)

#define SN74HC595_LATCH_HIGH   port_pin_set_output_level(SN74HC595_LATCH, true)
#define SN74HC595_LATCH_LOW    port_pin_set_output_level(SN74HC595_LATCH, false)

#define SN74HC595_CLEAR_HIGH   port_pin_set_output_level(SN74HC595_CLEAR, true)
#define SN74HC595_CLEAR_LOW    port_pin_set_output_level(SN74HC595_CLEAR, false)


struct spi_module spi_instance_sn74hc595;

void conf_spi_master(void);
void conf_gpio(void);

#endif /* SN74HC595_DRIVER_H_ */