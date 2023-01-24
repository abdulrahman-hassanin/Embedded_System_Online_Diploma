/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Abdulrahman Hassanin
 * @brief          : Toggle Led on STM32F103C6
 ******************************************************************************
 */

typedef volatile unsigned int vuint32_t;
#include <stdint.h>

// Register Address
// RCC
#define RCC_BASE		0x40021000
#define RCC_APB2ENR		*(vuint32_t *)(RCC_BASE   + 0x18)

// GPIO
#define GPIOA_BASE		0x40010800
#define GPIOA_CHR		*(vuint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_CRL		*(vuint32_t *)(GPIOA_BASE + 0x00)

#define GPIOA_ODR		*(vuint32_t *)(GPIOA_BASE + 0x0c)
#define GPIO13			(1UL<<13)

// EXTI
#define EXTI_BASE		0x40010400
#define EXTI_IMR		*(vuint32_t *)(EXTI_BASE + 0x00)
#define EXTI_RSTR		*(vuint32_t *)(EXTI_BASE + 0x08)
#define EXTI_PR			*(vuint32_t *)(EXTI_BASE + 0x14)

// AFIO
#define AFIO_BASE		0x40010000
#define AFIO_EXTICR1	*(vuint32_t *)(AFIO_BASE + 0x00)

#define NVIC_EXTIE0		*(vuint32_t *)(0xE000E100)


void clock_init()
{
	// Enable clock GPIOA
	RCC_APB2ENR |= (1<<2);

	// Bit 0 AFIOEN: Alternate function I/O clock enable
	RCC_APB2ENR |= (1<<0);
}

void GPIO_init()
{
	// pin 13 port A ouput
	GPIOA_CHR	&= 0xFF0FFFFF;
	GPIOA_CHR	|= 0x00200000;

	// pin 0 portA input floating
	// 01: Floating input(reset state)
	GPIOA_CRL |= (1<<2);
}

int main(void)
{
	// EXTI0  configuration (x=0) to port0
	AFIO_EXTICR1 = 0;

	// Enable EXTI Line 0 (Mask 1)
	EXTI_IMR |= (1<<0);

	// Enable Rising Trigger
	EXTI_RSTR |= (1<<0);

	// Enable NIVC Irq6 (EXTI0)
	NVIC_EXTIE0 |= (1<<6);

	while(1);
}

void EXTI0_IRQHandler()
{
	// IRQ is Happened EXTI0 >>> PORTA Pin 0 _|- rising edge
	// Toggle LED pin A13
	GPIOA_ODR ^= (1<<13);

	// clear pending Req for line 0
	EXTI_PR |= (1<<0);
}
