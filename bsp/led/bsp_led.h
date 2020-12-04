#ifndef __BSP_LED_H
#define __BSP_LED_H

void bsp_led_init(void);
void led_on(void);
void led_off(void);
void led_switch(int led, int status);

#endif