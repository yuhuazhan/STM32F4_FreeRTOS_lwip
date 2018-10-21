#include "sram.h"

volatile uint8_t extsram[MAX_SRAM_SIZE] __attribute__((section (".myExtSramSection")));


void sram_test(void)
{
	uint8_t src,dest;

	src = 0x0f;
	HAL_SRAM_Write_8b(&hsram1,(uint32_t *)0x68000000,&src,1);
	HAL_SRAM_Read_8b(&hsram1,(uint32_t *)0x68000000,&dest,1);

	while(dest != src);
	src = 0x37;
	HAL_SRAM_Write_8b(&hsram1,(uint32_t *)0x680FFFFF,&src,1);
	HAL_SRAM_Read_8b(&hsram1,(uint32_t *)0x680FFFFF,&dest,1);
	while(dest != src);


	src = 0x55;
	extsram[0] = src;
	dest = extsram[0];

	while(dest != src);

	src = 0x43;
	extsram[0xFFFFF] = src;
	dest = extsram[0xFFFFF];

	while(dest != src);
}
