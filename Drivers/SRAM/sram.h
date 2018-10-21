#ifndef __SRAM_H
#define __SRAM_H

#include "stm32f4xx_hal.h"

#define MAX_SRAM_SIZE 1024 * 1024// 1Mbytes
extern volatile uint8_t extsram[MAX_SRAM_SIZE] __attribute__((section (".myExtSramSection")));
void sram_test(void);




#endif
