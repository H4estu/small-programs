/*
 * File: Q1.c
 */

#include<stdio.h>
#include<stdlib.h>
#include"main.h"


struct student *allocate() {
	int struct_size = 10;
	struct student *studs = malloc(struct_size);
	
	return studs;
	
}


void generate(struct student *students) {
	
	int i, rand_id, rand_score;
	                   
	for(i = 0; i < 10; i++) {
		rand_id = rand() % 10;
		rand_score = rand() % 100;
		printf("rand_id %d\n", rand_id);
		printf("rand_score %d\n", rand_score);
	}  
		
	return;
	
}


void Q1() {
	
	struct student *stud = NULL;
	
	stud = allocate();
	printf("Pointer to student array: %p\n", stud);
	
	generate(stud);
	
	return;
}