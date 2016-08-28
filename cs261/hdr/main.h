#ifndef _MAIN_H
#define _MAIN_H


/* Q0 headers */
void fooA(int *iptr);

/* Q1 headers */
struct student {
	int id;
	int score;
};
void generate(struct student *students);
struct student *allocate();


/* "main" functions for each of the switch cases */
void Q0();
void Q1();
void Q2();
void Q3();
void Q4();
void Q5();


#endif