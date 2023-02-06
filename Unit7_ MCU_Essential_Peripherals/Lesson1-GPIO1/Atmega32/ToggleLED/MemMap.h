/*
 * MemMap.h
 *
 * Created: 26/01/2023 08:30:13
 *  Author: Abdulrahman Hassanin
 */ 


#ifndef MEMMAP_H_
#define MEMMAP_H_

#define PORTA	*((unsigned char *) 0x3B)
#define DDRA	*((unsigned char *) 0x3A)
#define PINA	*((unsigned char *) 0x39)

#define PORTB	*((unsigned char *) 0x38)
#define DDRB	*((unsigned char *) 0x37)
#define PINB	*((unsigned char *) 0x36)

#define PORTC	*((unsigned char *) 0x35)
#define DDRC	*((unsigned char *) 0x34)
#define PINC	*((unsigned char *) 0x33)

#define PORTD	*((unsigned char *) 0x32)
#define DDRD	*((unsigned char *) 0x31)
#define PIND	*((unsigned char *) 0x30)

#endif /* MEMMAP_H_ */