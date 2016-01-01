/*
 * tasks.c
 *
 * Created: 01.01.2016 21:09:47
 *  Author: Radu Donos
 */ 
#include <asf.h>
#include "tasks.h"

static void led_toggle(void)
{
	taskENTER_CRITICAL();
	{
		ioport_toggle_pin_level(LED_0_PIN);
	}
	taskEXIT_CRITICAL();
}

void lcd_write_alphanum_packet(const uint8_t *data)
{
	lcdca_write_packet(LCDCA_TDG_14SEG4COM, FIRST_14SEG_4C, data,
			WIDTH_14SEG_4C, LCDCA_CMCFG_DREV_LEFT);
}

void lcd_write_num_packet(const uint8_t *data)
{
	lcdca_write_packet(LCDCA_TDG_7SEG4COM, FIRST_7SEG_4C, data,
			WIDTH_7SEG_4C, LCDCA_CMCFG_DREV_LEFT);
}

void lcd_text_scrolling_start(const uint8_t *data, uint32_t length)
{
	/* Settings of automated display */
	struct lcdca_automated_char_config automated_char_config;

	automated_char_config.automated_mode = LCDCA_AUTOMATED_MODE_SCROLLING;
	automated_char_config.automated_timer = LCDCA_TIMER_FC0;
	automated_char_config.lcd_tdg = LCDCA_TDG_14SEG4COM;
	automated_char_config.stseg = FIRST_14SEG_4C;
	automated_char_config.dign = WIDTH_14SEG_4C;
	/* STEPS = string length - DIGN + 1 */
	automated_char_config.steps = length - WIDTH_14SEG_4C + 1;
	automated_char_config.dir_reverse = LCDCA_AUTOMATED_DIR_NOT_REVERSE;
	lcdca_automated_char_set_config(&automated_char_config);
	lcdca_automated_char_start(data, length);
}

void lcd_text_scrolling_stop(void)
{
	lcdca_automated_char_stop();
}


void vLed_task(void *pvParameters)
{
	const portTickType xDelayTime = 300 / portTICK_RATE_MS;
	for(;;)
	{
		led_toggle();
		vTaskDelay(xDelayTime);
	}
	vTaskDelete(NULL);
}

void vMisc_task(void *pvParameters)
{
	const portTickType xDelayTime = 500 / portTICK_RATE_MS;
	uint8_t const hello[] = "Hello world ";
	lcd_text_scrolling_start(hello, sizeof(hello));
	for(;;)
	{
		//lcdca_toggle_pixel(LCDA_ICON_PLAY);
		vTaskDelay(xDelayTime);
	}
	vTaskDelete(NULL);
}

void vLcd_task(void *pvParameters)
{
	const portTickType xDelayTime = 700 / portTICK_RATE_MS;
	const portTickType xDelaySignals = 50 / portTICK_RATE_MS;
	for(;;) {
		lcdca_toggle_pixel(LCDA_ICON_SIGNAL1);
		vTaskDelay(xDelaySignals);
		lcdca_toggle_pixel(LCDA_ICON_SIGNAL2);
		vTaskDelay(xDelaySignals);
		lcdca_toggle_pixel(LCDA_ICON_SIGNAL3);
		vTaskDelay(xDelaySignals);
		lcdca_toggle_pixel(LCDA_ICON_SIGNAL4);
		
		vTaskDelay(xDelayTime);
	}
	vTaskDelete(NULL);
}
