/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include "memory.h"

/***********************************************************
 Function Definitions
***********************************************************/
/* this function moves one-byte elements of number (length) from the address (src) to the address (dst)  */
uint8_t* my_memmove(uint8_t* src,uint8_t* dst,size_t length){

	//overlap check
	int32_t diff = dst-src;    //the number of overlapped elements
	if (diff < length && diff > 0){
	  //moving overlapped elements first
		for(uint8_t i=0;i<diff;i++){
		*(dst+diff+i) = *(src+diff+i);
		}
		length -= diff;   //new length after moving overlapped elements
	} 

	for (uint8_t i=0;i<length;i++)
		{
			*(dst+i) = *(src+i);
		}
	return dst;
}


/* this function moves one-byte elements of number (length) from the address (src) to the address (dst)  */
uint8_t* my_memcopy(uint8_t* src,uint8_t* dst,size_t length){

	for (uint8_t i=0;i<length;i++)
		{
			*(dst+i) = *(src+i);
		}
	return dst;
}


/* this function sets a number of one-byte elements (length) at the address (src) to the value (value) */
uint8_t* my_memset(uint8_t* src,size_t length,uint8_t value){

	for (uint8_t i=0;i<length;i++)
		{
			*(src+i) = value;
		}
	return src;
}


/* this function sets a number of one-byte elements (length) at the address (src) to zeros  */
uint8_t* my_memzero(uint8_t* src,size_t length){

	for (uint8_t i=0;i<length;i++)
		{
			*(src+i) = 0;
		}
	return src;
}


/* this function reverses the order of a number of bytes (length) starting from the address (src) */
uint8_t* my_reverse(uint8_t* src,size_t length){
	uint8_t temp=0;
	for (uint8_t i=0;i<length/2;i++)
		{
			temp = *(src+i);
			*(src+i) = *(src+length-i-1);
			*(src+length-i-1) = temp;
		}
	return src;
}


/* this function allocates a number of bytes (length) in the heap memory and returns a pointer to thier address */
int32_t* reserve_words(size_t length){

	return malloc(4*length);    //size of int32_t = 4 bytes
}


/* this function frees an allocated bytes from the heap memory from an address (src)  */
void free_words(uint32_t* src){

	free(src);
}







void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

