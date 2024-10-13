#ifndef CALC_H
#define CALC_H

// Function to calculate total score and grade letter for a student
void calculateCase1(char *fields[], int *grade_total, char *grade_letter);

// Function to update the grade mappings for A, B, C, D, and F
void updateGradeMap();

// Function to display grade distribution using asterisks
void displayGradeDis(int countA, int countB, int countC, int countD, int countF);

// Function to count the number of each grade (A, B, C, D, F)
void countGrades(char grade[], int *countA, int *countB, int *countC, int *countD, int *countF);

// Function for handling case 2 (displaying grade distribution)
void case2(char grade[]);

#endif