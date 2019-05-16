

#include "data.h"

/* this function converts a 4-byte signed integer (data) to its ASCI char array (ptr) in a numeric system (base) and also returns the number of digits */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){

    uint8_t counter= 0;    //this counts the number of digits
    uint8_t sign =0;

    if (data<0) { sign =1; data*=-1; }

    while(data>0){

		if (data%base > 9) //for base 16
    		*(ptr+counter) = (data%base) - 10 + 'A';  //transform the numbers (10,11,12,13,14,15) to (A,B,C,D,E,F)

        else
			*(ptr+counter) = data % base + '0' ;   //add the '0' to convert the digit into ASCI
        data /=base;
        counter++;
    }
    if (sign==1) *(ptr+counter++)= '-';
    my_reverse(ptr,counter);
    *(ptr+counter)= 0;   //null character
    return counter;
}


/* this function converts an ASCI char array (ptr) and returns a 4-byte signed integer given a numeric system (base) */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
	int32_t sum =0;  //this will hold the resultant decimal number
	uint8_t sign= 0;
	
	//sign check
	if (*ptr == '-') {
		sign =1;
		ptr++;
		digits--;
	}

	for(uint8_t i=0;i<digits;i++){
		if (*(ptr+digits-1-i) >= 'A' )
			sum += (*(ptr+digits-1-i)-'A'+10) * pow(base,i);
		else 
			sum += (*(ptr+digits-1-i)-'0') * pow(base,i);
	}

	if (sign==1) sum*=-1;
	return sum;
}
