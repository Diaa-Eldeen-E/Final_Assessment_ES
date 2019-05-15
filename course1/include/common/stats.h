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
 * @file stats.h
 * @brief this file contains seven functions declrations for preforming some    * anaylsis on numeric arrays  
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
 * @author   Diaa ad-Deen Ahmad
 * @date     1-5-2019
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief this function prints the array statistics
 *
 * this function calls other functions to get the array median , mean , max and * minimum , then it prints the results for the user
 *
 * @arguments : arr is the given array 
 * n is the number of elements
 *
 * @return : the function returns no thing, it just prints the results
 */
void print_statistics(unsigned char arr[],unsigned int n);

/**
 * @brief this function prints the array elements sorted from the largest to 
 * smallest
 *
 * this function calls the sort function then it prints the sorted array 
 * elements to the screen
 *
 * @arguments : arr is the given array 
 * n is the number of elements
 *
 * @return : the function returns no thing, it just prints the results
 */
void print_array(unsigned char arr[],unsigned int n);

/**
 * @brief this function finds the array median
 *
 * this function calls the sort array , then it has two cases , if the array 
 * has odd n elements then the median index is (n+1)/2 , if it's even then we
 * have two medians n/2 , (n/2)+1 , so we get thier mean
 *
 * @arguments : arr is the given array 
 * n is the number of elements
 *
 * @return : the function returns the median element
 */
unsigned char find_median(unsigned char arr[],unsigned int n);

/**
 * @brief this function calculates the array mean value
 *
 * this function calculates the mean by adding all the array elements and 
 * dividing by number of elements
 *
 * @arguments : arr is the given array 
 * n is the number of elements
 *
 * @return : the function returns the mean value of the array
 */
unsigned char find_mean(unsigned char arr[],unsigned int n);

/**
 * @brief this function finds the array maximum value
 *
 * this function calls the sort array then it the max value is at index 0
 *
 * @arguments : arr is the given array 
 * n is the number of elements
 *
 * @return : the function returns the maximum value element
 */
unsigned char find_maximum(unsigned char arr[],unsigned int n);

/**
 * @brief this function finds the array minimum value
 *
 * this function calls the sort array then it the min value is at index n-1
 *
 * @arguments : arr is the given array 
 * n is the number of elements
 *
 * @return : the function returns the minimum value element
 */
unsigned char find_minimum(unsigned char arr[],unsigned int n);

/**
 * @brief this function sorts an array , from the largest to the smallest
 *
 * this function sorts the array by comparing each element with the following 
 * elements
 *
 * @arguements: arr is the given unsorted array 
 *  n is the number of elements
 *
 * @return : the function returns the sorted array
 */
unsigned char* sort_array(unsigned char arr[],unsigned int n);

#endif /* __STATS_H__ */
