/*
 * sn74hc595_driver.c
 *
 * Created: 2022-05-10
 *  Author: Adithya Yuri
 */ 

#include "app/sn74hc595_driver.h"


void conf_spi_master()
{
	struct spi_config config_spi_master;
	spi_get_config_defaults(&config_spi_master);

	config_spi_master.mux_setting = SN74HC595_MUX_SETTING;
	config_spi_master.pinmux_pad0 = SN74HC595_PINMUX_PAD0;
	config_spi_master.pinmux_pad1 = SN74HC595_PINMUX_PAD1;
	config_spi_master.pinmux_pad2 = SN74HC595_PINMUX_PAD2;
	config_spi_master.pinmux_pad3 = SN74HC595_PINMUX_PAD3;
	config_spi_master.mode_specific.master.baudrate = SN74HC595_BUAD;

	spi_init(&spi_instance_sn74hc595, SN74HC595_SPI_MODULE, &config_spi_master);
	spi_enable(&spi_instance_sn74hc595);	

}

void conf_gpio()
{
	struct port_config pin_conf;
	port_get_config_defaults(&pin_conf);

	// Configure PIN as output
	pin_conf.direction  = PORT_PIN_DIR_OUTPUT;
	port_pin_set_config(SN74HC595_OUTEN, &pin_conf); // Configure Output Enable PIN as output
	port_pin_set_config(SN74HC595_LATCH, &pin_conf); // Configure Latch PIN as output
	port_pin_set_config(SN74HC595_CLEAR, &pin_conf); // Configure Master clear PIN as output
	
	// Set pin initial state
	port_pin_set_output_level(SN74HC595_OUTEN, true);  // Active low pin
	port_pin_set_output_level(SN74HC595_LATCH, false); // Active high pin
	port_pin_set_output_level(SN74HC595_CLEAR, true);  // Active low pin
	
}