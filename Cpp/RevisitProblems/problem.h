#ifndef PROBLEM_H
#define PROBLEM_H
#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<utility>
#define MAX 10
void hello_world();
void upper_or_lower_or_numeric(char ch); // check if a character is upper case or lower case or numeric or special one.
int sum_of_n_natural_numbers(int terms); // sum of n natural numbers using loop.
int sum_of_n_even_numbers(int terms);// sum of n even whole numbers.
void pattern1(int rows); // star squar pattern. 
void pattern2(int rows); 
void pattern3(int rows); // star right triangle pattern.
void pattern4(int rows); 
void pattern5(int rows);
void pattern6(int rows);
void pattern7(int rows);
void pattern8(int rows);
void pattern9(int rows); // star right triangle with spaces.
void pattern10(int rows);
void pattern11(int rows);
void pattern12(int rows);
void pattern13(int rows); // star triangle.
void pattern14(int rows); 
void pattern15(int rows);
void fib(int terms);
void product_sum_of_digits(int number);
int reverse(int number); // reverse a number.
int bit_count(int number);// bit count.
int complement_of_number(int number); // complement of number.
int two_complement_of_negative_number(int number);//2's complement of negative number
int total_number_of_notes(int money);// find total number of note's using notes.
void ap_series(int seed);// ap series
int count_setbits(int first, int second);// count set bits.
int factorial(int number);// factorial of a number.
int sum_of_array_elements(int *arr,int size); // sum of array elements.
bool linear_search(int *arr, int size,int el); // linear search
int find_unique_element(int *arr,int size);// find unique element in an array.
bool unique_occurrences(int *arr, int size); // unique number of occurrences.
void swap_alternate(int *arr, int size);// swap alternate elements.
int find_duplicate(int *arr, int size);// find duplicate in array.
void print(int *arr, int size); // prints elements of array.
void find_all_duplicates(int *arr, int size);// leetcode.
void intersection_of_arrays(int *arr,int size,int *arr2,int size2); // intersection of arrays.
void pair_sum(int *arr,int size,int sum);// pair sum
void sort01(int *arr, int size);// sort 0 and 1 
void sort012(int *arr, int size);// sort 0 ,1 and 2
#endif
