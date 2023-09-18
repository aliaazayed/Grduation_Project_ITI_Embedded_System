/*
*<<<<<<<<<<<<<<<<<<<<<BIT_MATH_H>>>>>>>>>>>>>>>>>>>>>>>>
* Author : ALIAA ESLAM ZAYED
* Created: 11 /8/2023
* Layer  : LIB
*/


#ifndef  BIT_MATH_H_
#define  BIT_MATH_H_

#define REGISTER_SIZE 8

#define SET_BIT(reg,bit)    reg|=(1<<bit)
#define CLR_BIT(reg,bit)    reg&=(~(1<<bit))
#define GET_BIT(reg,bit)    (reg&(1<<bit))>>bit
#define TOG_BIT(reg,bit)     reg^=(1<<bit)

#endif