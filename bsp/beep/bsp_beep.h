#ifndef __BSP_BEEP_H
#define __BSP_BEEP_H

#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "MCIMX6Y2.h"
#include "cc.h"

void bsp_beep_init(void);
void beep_switch(uint8_t status);

#endif