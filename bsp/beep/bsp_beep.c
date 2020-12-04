#include "bsp_beep.h"

void bsp_beep_init(void)
{
    IOMUXC_SetPinMux(IOMUXC_SNVS_SNVS_TAMPER1_GPIO5_IO01, 0);
    IOMUXC_SetPinConfig(IOMUXC_SNVS_SNVS_TAMPER1_GPIO5_IO01, 0x10B0);
    GPIO5->GDIR |= __BIT(1);    /*Set GPIO5_IO01 as output*/
    GPIO5->DR   |= __BIT(1);    /*close the beep*/
}

void beep_switch(uint8_t status)
{
    if(ON == status)
    {
        GPIO5->DR &= ~__BIT(1);
    }
    else
    {
        GPIO5->DR |= __BIT(1); 
    }
}