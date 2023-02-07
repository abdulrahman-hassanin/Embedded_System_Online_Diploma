/*
 * commonMacros.h
 *
 * Created: 28/01/2023 12:33:01
 *  Author: Abdulrahman
 */ 


#ifndef COMMONMACROS_H_
#define COMMONMACROS_H_

#define SET_BIT(REG,BIT) (REG|=(1<<BIT))

#define CLEAR_BIT(REG,BIT) (REG&=(~(1<<BIT)))

#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))


#endif /* COMMONMACROS_H_ */