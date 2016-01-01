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

int main (void)
{
	sysclk_init();
	board_init();
	init_lcd();

	lcdca_set_pixel(LCDA_ICON_ATMEL);

	while (1);
}
