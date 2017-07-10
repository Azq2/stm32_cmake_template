#include "stm32f10x.h"

int main(void) {
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	
	GPIO_InitTypeDef gpio;
	
	gpio.GPIO_Pin       = GPIO_Pin_13;
	gpio.GPIO_Speed     = GPIO_Speed_50MHz;
	gpio.GPIO_Mode      = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOC, &gpio);
	
	int j;
	while (1) {
		GPIO_WriteBit(GPIOC, GPIO_Pin_13, j % 2 ? 1 : 0);
		for (int i = 0; i < 10000000; ++i);
		++j;
	}
}
