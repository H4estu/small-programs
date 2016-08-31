/*
 * File: Q1.c
 */

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"main.h"

struct student *allocate() {
	struct student *studs = malloc(10*sizeof(struct student));
	// Error checking
	if (NULL == studs) {
		fprintf(stderr, "malloc failed\n");
		exit(-1);
	}
	return studs;
}


void generate(struct student *students) {
	
	int i, rand_id, rand_score, tmp;
	int ids[10];
	int length;
	
	length = sizeof(ids)/sizeof(ids[0]);
	
	// generate array of ids 
	for (i = 0; i < length; i++) {
		ids[i] = i;
	}

	// Fisher-Yates-Durstenfeld algorithm for shuffling array
	for (i = length-1; i > 0; i--) {
		rand_id = rand() % i;
		// swap id[current] and id[i]
		tmp = ids[i];
		ids[i] = ids[rand_id];
		ids[rand_id] = tmp;
	}			
					
	// populate student struct with ids and scores   
	for(i = 0; i < length; i++) {
		students[i].id = ids[i];
		rand_score = rand() % 100;
		students[i].score = rand_score;
	}  
	return;
}

void output(struct student *students) {
	
	int i, length;
	length = 10;
	
	for (i = 0; i < length; i++) {
		printf("student id: %d\n", students[i].id);
		printf("student score %d\n", students[i].score);
	}
	return;
}


void summary(struct student *students) {
	
	int min_score, max_score, i, length;
	float av_score = 0;	
	length = 10;
	
	for (i = 0; i < length; i++) {
		if (i == 0) {
			min_score = students[i].score;
			max_score = students[i].score;
		}
		if (students[i].score < min_score) {
			min_score = students[i].score;
		}
		if (students[i].score > max_score) {
			max_score = students[i].score;
		}
		av_score += students[i].score;
	}
	av_score /= length;
	
	printf("Minimum score: %d\n", min_score);
	printf("Maximum score: %d\n", max_score);
	printf("Average score: %f\n", av_score);
	
	return;
}

void deallocate(struct student *students) {
	
	assert(NULL != 0);
	
	free(students);
}

void Q1() {
	
	struct student *stud = NULL;
	printf("Allocating space...\n");
	stud = allocate();
	printf("Pointer to student array: %p\n", stud);
	
	printf("Generating scores and ids...\n");
	generate(stud);
	
	output(stud);
	
	printf("Summary statistics...\n");
	summary(stud);
	
	printf("Freeing memory...\n");
	
	return;
}