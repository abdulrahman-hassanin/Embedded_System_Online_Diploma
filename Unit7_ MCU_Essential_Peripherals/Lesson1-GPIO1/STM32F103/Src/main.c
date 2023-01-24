/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Abdulrahman Hassanin
 * @brief          : Main program body
 *****************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

typedef volatile unsigned int vuint32_t;
#include <stdint.h>

// Register Address
// RCC
#define RCC_BASE		0x40021000
#define RCC_APB2ENR		*(vuint32_t *)(RCC_BASE   + 0x18)

// GPIO
#define GPIOA_BASE		0x40010800
#define GPIOA_CRH		*(vuint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_CRL		*(vuint32_t *)(GPIOA_BASE + 0x00)
#define GPIOA_ODR		*(vuint32_t *)(GPIOA_BASE + 0x0c)
#define GPIOA_IDR		*(vuint32_t *)(GPIOA_BASE + 0x08)

#define GPIO13			(1UL<<13)

#define GPIOB_BASE		0x40010C00
#define GPIOB_CRH		*(vuint32_t *)(GPIOB_BASE + 0x04)
#define GPIOB_CRL		*(vuint32_t *)(GPIOB_BASE + 0x00)
#define GPIOB_ODR		*(vuint32_t *)(GPIOB_BASE + 0x0c)
#define GPIOA_IDR		*(vuint32_t *)(GPIOA_BASE + 0x08)


void clock_init()
{
	// Enable clock GPIOA
	RCC_APB2ENR |= (1<<2);
	// Enable clock GPIOB
	RCC_APB2ENR |= (1<<3);
}

void GPIO_init()
{
	GPIOA_CRL = 0x0;
	GPIOB_CRL = 0x0;

	// PA1 input HighZ
	GPIOA_CRL |= 1<<6;

	// PB1 output push-pull mode
	// CNF 00: General purpose output push-pull
	GPIOB_CRL &= ~(0b11<6);
	// MODE 01: output mode, max speed 10 MHz
	GPIOB_CRL |= (0b01) << 4;

	// PA13 input HighZ
	GPIOB_CRL &= ~(0b11<20);
	GPIOB_CRL |= (0b01<22);

	// PB13 output push-pull mode
	GPIOB_CRH |= (0b01<<20);
	GPIOB_CRH &= ~(0b11<<22);
}

void my_wait(int x)
{
	unsigned int i, j;
	for(i=0; i<x; i++)
		for(j=0; j<255; j++);
}

int main(void)
{
	clock_init();
	GPIO_init();

	while(1)
	{
		// PA1 >> connected to external PUR
		if( ((GPIOA_IDR & (1<<1)) >> 1) == 0 ) // press
		{
			GPIOB_ODR ^= 1<<1;
			while(((GPIOA_IDR & (1<<1)) >> 1) == 0); // single press
		}
		// PA13 >> connected to external PDR
		if( ((GPIOA_IDR & (1<<13)) >> 13) == 1 ) // Multi-press
		{
			GPIOB_ODR ^= 1<<13;
		}
		my_wait(1);
	}
}
