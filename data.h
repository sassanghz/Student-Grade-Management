#ifndef DATA_H
#define DATA_H

#define LINE_LENGTH 256
#define MAX_STUDENTS 100

// Function to display and process case 1 (grade sheet display)
void case1(char grade[], char *fields[][8], int *studentCount);

// Clears the console screen
void clearScreen();

// Function to update the last name of a student based on ID
void updateLastName();

// Function to update the exam grade of a student based on ID
void updateExamGrade(char *fields[][8], int studentCount);

// Function to delete a student from the records
void deleteStudent(char *fields[][8], int *studentCount);

#endif