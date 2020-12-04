#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "MCIMX6Y2.h"
#include "bsp_led.h"
#include "bsp_delay.h"
#include "bsp_clk.h"
#include "bsp_beep.h"
#include "bsp_key.h"

int main(void)
{
    int i = 0;
    int key_value = 0;
    unsigned char led_state = OFF;
    unsigned char beep_state = OFF;

    clk_init();
    bsp_led_init();
    bsp_beep_init();
    bsp_key_init();

    while(1)
    {
        key_value = key_getvalue();
        if(key_value)
        {
            switch(key_value)
            {
                case 1:
                    beep_state = !beep_state;
                    beep_switch(beep_state);
                    break;
            }
        }
        if(50==(i++))
        {
            i=0;
            led_state = !led_state;
            led_switch(LED0,led_state);
        }
        delay(10);
      /*  led_off();
        beep_switch(OFF);
        delay(500);
        
        led_on();
        beep_switch(ON);
        delay(500);*/
    }
    return 0;
}