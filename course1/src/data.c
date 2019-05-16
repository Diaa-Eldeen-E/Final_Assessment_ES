

#include "data.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){

    uint8_t counter= 0;
    uint8_t sign =0;
    if (data<0) {sign =1; data*=-1;}
    while(data>0){
       *(ptr+counter) = data % base + '0' ;
        data /=base;
        counter++;
    }
    if (sign==1) *(ptr+counter++)= '-';
    my_reverse(ptr,counter);
    *(ptr+counter)= 0;   //null character
    return counter;
}


int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
	int32_t sum =0;
	uint8_t sign= 0;
	if (*ptr == '-') {
		sign =1;
		ptr++;
		digits--;
	}
	for(uint8_t i=0;i<digits;i++){
		sum += (*(ptr+digits-1-i)-'0') * pow(base,i);
	}
	if (sign==1) sum*=-1;
	return sum;
}
