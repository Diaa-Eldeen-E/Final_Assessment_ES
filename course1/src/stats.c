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
 * @file stats.c 
 * @brief this file contains seven functions definitions for preforming some    * anaylsis on numeric arrays 
 *
 * The functions are as follows :
 *1- print_statistics() - A function that prints the statistics of an array     *including minimum, maximum, mean, and median.
 *2- print_array() - Given an array of data and a length, prints the array to   *the screen
 *3-find_median() - Given an array of data and a length, returns the median     *value
 *4- find_mean() - Given an array of data and a length, returns the mean
 *5- find_maximum() - Given an array of data and a length, returns the maximum
 *6- find_minimum() - Given an array of data and a length, returns the minimum
 *7- sort_array() - Given an array of data and a length, sorts the array from   * largest to smallest.
 *
 * @author Diaa ad-Deen Ahmad
 * @date   1-5-2019
 *
 */



#include <stdio.h>
#include "stats.h"
#include "platform.h"

/* Size of the Data Set */
#define SIZE (40)
/*
int main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};
  // Other Variable Declarations Go Here  
   unsigned int n= sizeof(test) / sizeof(unsigned char) ;   //number of elements
  // Statistics and Printing Functions Go Here 
   print_array(test,n);       //prints the sorted array
   print_statistics(test,n);  //prints the array median, mean, max, min 
   return 0;
}*/

/* Add other Implementation File Code Here */
void print_statistics(unsigned char arr[],unsigned int n){

   printf("Array Median        = %d\n",find_median(arr,n) );
   printf("Array Mean value    = %d\n",find_mean(arr,n) );
   printf("Array Maximum value = %d\n",find_maximum(arr,n) );
   printf("Array Median value  = %d\n\n",find_minimum(arr,n) );
}


void print_array(unsigned char arr[],unsigned int n){
#if defined (VERBOSE)
   PRINTF("\nThe array elements:\n\n      ");
   for (char i =1; i<=n; i++)
   {
      PRINTF("%3d ", arr[i-1]);
      if(i%8==0) PRINTF("\n      "); //new line every 8 elements
   }
   PRINTF("\n\n");
#endif
}

unsigned char find_median(unsigned char arr[],unsigned int n){

   unsigned char* sortedArray=sort_array(arr,n);
   if (n%2==0) //if the number is even
      {
          double temp=(double) (sortedArray[(n-1)/2]+sortedArray[((n-1)/2)+1])/2;
          //rounding the value
          if (temp+0.5>= ((unsigned char) temp) +1 ){
             return  (unsigned char) temp+1;
          }
          else
          {
             return (unsigned char) temp ;
          }
	  
      }
   else        //if the number is odd
      {
          return sortedArray[(n+1)/2];  
      }
}

unsigned char find_mean(unsigned char arr[],unsigned int n){

   double sum=0;
   for (unsigned int i=0; i<n ;i++)
   {
      sum+= arr[i];
   }
   //rounding the value

   if (sum+0.5>= (unsigned int) sum +1 ){
      return ( ((unsigned int) sum)+1)/n;
   }
   else
   {
      return (unsigned int) sum /n;
   }

}

unsigned char find_maximum(unsigned char arr[],unsigned int n){

   return sort_array(arr,n)[0];

}

unsigned char find_minimum(unsigned char arr[],unsigned int n){

   return sort_array(arr,n)[n-1];

}

unsigned char* sort_array(unsigned char arr[],unsigned int n){

   unsigned char temp=0;
   for (unsigned int i=0; i<n ; i++)
   {
      for (unsigned int j=i+1; j<n; j++)
      {
         if (arr[i] < arr[j])
         {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
         } 
      }
   }
   return arr;
}


