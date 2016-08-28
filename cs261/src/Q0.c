/*
 * File: Q0.c
 */

#include<stdio.h>
#include "main.h"

void fooA(int *iptr) {
	
	printf("Value of iptr/x: %d\n", *iptr);
	printf("Address of iptr/x: %p\n", iptr);
	return;
}

void Q0() {
	
	int x = 23; 
	
	printf("Address of x: %p\n", &x);
	fooA(&x);
	
	printf("The value of x is: %d\n",x);
	
	return;
}