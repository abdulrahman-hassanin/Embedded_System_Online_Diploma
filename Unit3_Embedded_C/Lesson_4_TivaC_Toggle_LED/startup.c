/*
 *  startup.c
 *  Abdulrahman Hassanin
 */

#include <stdint.h>
extern int main(void);

void Reset_Handler(void);

void Default_Handler()
{
	Reset_Handler();
}
void NMI_Handler(void) __attribute__((weak, alias("Default_Handler")));
void H_Fault_Handler(void) __attribute__((weak, alias("Default_Handler")));

// booking 1024B loacted by .bss through unintialized array of 256 Element (256*24=1024)
// this avoiding resolving statck_top symbol of linker script
static unsigned long Stack_top[256];

void (*const g_p_fn_Vectors[]) ()  __attribute__((section(".vectors"))) =
{
	(void (*)()) ((unsigned long)Stack_top+sizeof(Stack_top)),	
	&Reset_Handler,
	&NMI_Handler,
	&H_Fault_Handler,
};

extern unsigned int _E_text;
extern unsigned int _S_DATA;
extern unsigned int _E_DATA;
extern unsigned int _S_bss;
extern unsigned int _E_bss;

void Reset_Handler(void)
{
	// copy data section from Flash ro RAM
	// casting to char to copy byte by byte
	// but we use allignment so we can copy 4 bytes (int)
	// However we made it for saftey
	unsigned int DATA_size = (unsigned char*)&_E_DATA - (unsigned char*)&_S_DATA ;
	unsigned char* P_src = (unsigned char*)&_E_text ;
	unsigned char* P_dst = (unsigned char*)&_S_DATA ;
	
	for(int i=0; i<DATA_size; i++) {
		*((unsigned char*)P_dst++) = *((unsigned char*)P_src++);
		
	}
	
	// init .bss section in SRAM = 0
	unsigned int bss_size = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss;
	P_dst = (unsigned char*)&_S_bss;
	for(int i=0; i<bss_size; i++) {
		*((unsigned char*)P_dst++) = (unsigned char) 0;
		
	}
	
	// jump main()
	main();
}