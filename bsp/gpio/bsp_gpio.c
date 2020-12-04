#include "bsp_gpio.h"

void gpio_init(GPIO_Type *base, int pin, gpio_pin_config_t *config)
{
    if(config->direction == kGPIO_DigitalInput)
    {
        base->GDIR &= ~__BIT(pin);
    }
    else
    {
        base->GDIR |= __BIT(pin);
        gpio_pinwrite(base, pin, config->outputLogic);
    }
}

int gpio_pinread(GPIO_Type *base, int pin)
{
    return(((base->DR)>>pin)&0x01);
}

void gpio_pinwrite(GPIO_Type *base, int pin, int value)
{
    if(value == 0U)
    {
        base->DR &= ~__BIT(pin);
    }
    else
    {
        base->DR |= __BIT(pin);
    }    
}