/*
 * tasks.h
 *
 * Created: 01.01.2016 21:11:39
 *  Author: Gindul
 */ 


#ifndef TASKS_H_
#define TASKS_H_

#define FIRST_7SEG_4C 10
#define WIDTH_7SEG_4C 4

#define FIRST_14SEG_4C 4
#define WIDTH_14SEG_4C 7

void vLed_task(void *pvParameters);
void vMisc_task(void *pvParameters);
void vLcd_task(void *pvParameters);


#endif /* TASKS_H_ */