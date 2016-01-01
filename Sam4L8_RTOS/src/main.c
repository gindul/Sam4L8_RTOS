/************************************************************************/
/* @Author Radu DONOS                                                   */
/* @project Sam4L8_RTOS                                                 */
/************************************************************************/

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
#include <asf.h>
#include "tasks.h"

int main (void)
{
	sysclk_init();
	board_init();
	init_lcd();
	configure_pins();

	lcdca_set_pixel(LCDA_ICON_ATMEL);
	
	xTaskCreate(vLed_task, "Task LED", configMINIMAL_STACK_SIZE*2, NULL, tskIDLE_PRIORITY+1, NULL);
	xTaskCreate(vMisc_task, "Task Misc", configMINIMAL_STACK_SIZE*4, NULL, tskIDLE_PRIORITY+2, NULL);
	xTaskCreate(vLcd_task, "Task LCD", configMINIMAL_STACK_SIZE*2, NULL, tskIDLE_PRIORITY+4, NULL);

	vTaskStartScheduler();
	while (1);
}

// Config functions [1/1/2016 Radu DONOS]
// ----------------------------------------------------------------------
void init_lcd(void)
{
	struct lcdca_config lcdca_cfg;
	
	/* Turn on LCD back light */
	ioport_set_pin_dir(PIN_PC05D_TC1_B2, IOPORT_DIR_OUTPUT);
	ioport_set_pin_level(PIN_PC05D_TC1_B2, IOPORT_PIN_LEVEL_HIGH);
	
	// LCDCA Controller initialization
	// - Clock,
	// - Connect to C42364A glass LCD component,
	// - Timing: 64 Hz frame rate & low power waveform, FC0, FC1, FC2
	// - Interrupt: off.
	lcdca_cfg.port_mask = PORT_MASK;
	lcdca_cfg.x_bias = false;
	lcdca_cfg.lp_wave = true;
	lcdca_cfg.duty_type = LCD_DUTY;
	lcdca_cfg.lcd_pres = false;
	lcdca_cfg.lcd_clkdiv = 3;
	lcdca_cfg.fc0 = 16;
	lcdca_cfg.fc1 = 2;
	lcdca_cfg.fc2 = 6;
	lcdca_cfg.contrast = LCD_CONTRAST_LEVEL;
	lcdca_clk_init();
	lcdca_set_config(&lcdca_cfg);
	lcdca_enable();
	lcdca_enable_timer(LCDCA_TIMER_FC0);
	lcdca_enable_timer(LCDCA_TIMER_FC1);
	lcdca_enable_timer(LCDCA_TIMER_FC2);
}

inline void init_extled(int pin)
{
	ioport_set_pin_dir(pin, IOPORT_DIR_OUTPUT);
	ioport_set_pin_level(pin, IOPORT_PIN_LEVEL_HIGH);
}

void configure_pins(void)
{
	/* Initialize ext LED, turned off */
	//init_extled(EXT3_LED_1);
	//init_extled(EXT3_LED_2);
	//init_extled(EXT3_LED_3);
}

// FreeRTOS Hooks [1/1/2016 Radu DONOS]
// ----------------------------------------------------------------------
void vApplicationMallocFailedHook( void )
{
	taskDISABLE_INTERRUPTS();
	while(1) {
		
	}
}

void vApplicationStackOverflowHook( xTaskHandle pxTask, char *pcTaskName )
{
	( void ) pcTaskName;
	( void ) pxTask;

	/* Run time stack overflow checking is performed if
	configCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2.  This hook
	function is called if a stack overflow is detected. */
	taskDISABLE_INTERRUPTS();
	for( ;; );
}

//interrupts handlers
void HardFault_Handler(void)
{
	while(1) {
		
	}
}
