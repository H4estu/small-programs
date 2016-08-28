/*
 * File: main.c
 * Usage: ./main <arg> 
 * <arg> is one of q0, q1, ..., q5
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "main.h"

int main(int argc, char *argv[]) {

	char prog;

	if (argc >= 2) {
		prog = *argv[1];
	}
	else {
		printf("Pass argument to run test (0-5)\n");
		exit(0);
	}
	
	printf("%s\n", argv[1]);
	
	switch(prog) {
		case '0':
			printf("**********Executing Q0.c**********\n");
			Q0();
			break;
		case '1':
			printf("***********Executing Q1.c**********\n");
			Q1();
			break;
		default:
			printf("I'm the default case\n");
	}
	
	return 0;
}