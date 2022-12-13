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
#define RCC_BASE		0x40021000
#define GPIOA_BASE		0x40010800
#define RCC_APB2ENR		*(vuint32_t *)(RCC_BASE   + 0x18)
#define GPIOA_CHR		*(vuint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR		*(vuint32_t *)(GPIOA_BASE + 0x0c)

extern void NMI_Handler(void)
{
	
}

extern void Bus_Fault(void)
{
	
}

// bit field register ODR
typedef union{
	vuint32_t	all_fields;
	struct {
		vuint32_t reserved:13;
		vuint32_t P_13:1;
	} Pin;
} R_ODR_t;

volatile R_ODR_t* R_ODR = (volatile R_ODR_t*)(GPIOA_BASE + 0x0C);
unsigned char g_variables[3] = {1, 2, 3};
unsigned char const const_variables[3] = {1, 2, 3};
volatile unsigned char bss_var[3];

int main(void)
{
	RCC_APB2ENR |= (1<<2);

	GPIOA_CHR	&= 0xFF0FFFFF;
	GPIOA_CHR	|= 0x00200000;

	while(1)
	{
		R_ODR->Pin.P_13 = 1;
		for(int i=0; i<50000; i++);
		R_ODR->Pin.P_13 = 0;
		for(int i=0; i<50000; i++);
	}
}
