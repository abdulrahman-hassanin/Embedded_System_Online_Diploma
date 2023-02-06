/*
 * utils.h
 *
 * Created: 26/01/2023 08:39:37
 * Author : Abdulrahman Hassanin
 */ 


#ifndef UTILS_H_
#define UTILS_H_


#define SetBit(reg, bit)	(reg |= (1<<bit))

#define ClearBit(reg, bit)	(reg &= ~(1<<bit))

#define ReadBit(reg, bit)	((reg>>bit)&1)

#define Toggle(reg, bit)	(reg ^= (1<<bit))

#endif /* UTILS_H_ */