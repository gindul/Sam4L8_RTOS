/**
 * \file
 *
 * \brief SAM4L8 Xplained Pro board configuration
 *
 * Copyright (C) 2014-2015 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 * 
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 * 
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#ifndef CONF_BOARD_H_INCLUDED
#define CONF_BOARD_H_INCLUDED

//#define CONF_BOARD_KEEP_WATCHDOG_AT_INIT

#define PORT_MASK 40
#define LCD_DUTY LCDCA_DUTY_1_4
#define LCD_CONTRAST_LEVEL 30

#define LCDA_ICON_USB 1,1
#define LCDA_ICON_ATMEL 0,1
#define LCDA_ICON_SIGNAL1 3,3
#define LCDA_ICON_SIGNAL2 3,2
#define LCDA_ICON_SIGNAL3 2,3
#define LCDA_ICON_SIGNAL4 2,2
#define LCDA_ICON_PLAY 2,1

#define EXT3_LED_1 EXT3_PIN_7
#define EXT3_LED_2 EXT3_PIN_8
#define EXT3_LED_3 EXT3_PIN_6

void configure_pins(void);
void init_lcd(void);

#endif /* CONF_BOARD_H_INCLUDED */
