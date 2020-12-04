#include "bsp_led.h"
#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "MCIMX6Y2.h"
#include "cc.h"


void bsp_led_init(void)
{
    //IOMUX_SW_MUX->GPIO1_IO03 = 0x05;
    //IOMUX_SW_PAD->GPIO1_IO03 = 0x10B0;
    IOMUXC_SetPinMux(IOMUXC_GPIO1_IO03_GPIO1_IO03,0);
    IOMUXC_SetPinConfig(IOMUXC_GPIO1_IO03_GPIO1_IO03,0x10B0);
    GPIO1->GDIR |= __BIT(3);
    GPIO1->DR &=~__BIT(3);
}

void led_on(void)
{
    GPIO1->DR &= ~__BIT(3);
}

void led_off(void)
{
    GPIO1->DR |= __BIT(3);
}

void led_switch(int led, int status)
{
    switch(led)
    {
        case LED0:
            if(status == ON)
                led_on();
            else if(OFF == status)
                led_off();
            break;
    }
}