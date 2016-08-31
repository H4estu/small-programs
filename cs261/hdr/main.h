#ifndef _MAIN_H
#define _MAIN_H


/* Q0 headers */
void fooA(int *iptr);

/* Q1 headers */
struct student {
	int id;
	int score;
};
struct student *allocate();
void generate(struct student *students);
void output(struct student *students);
void summary(struct student *students);
void deallocate(struct student *students);

/* "main" functions for each of the switch cases */
void Q0();
void Q1();
void Q2();
void Q3();
void Q4();
void Q5();


#endif