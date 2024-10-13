#ifndef ORDERING_H
#define ORDERING_H

#define LINE_LENGTH 256
#define MAX_STUDENTS 100

typedef struct {
    int id; // Student ID
    char lastName[50]; // Last Name
    char firstName[50]; // First Name
    int scores[5]; // Array of scores (A1, A2, A3, Midterm, Exam)
    int total; // Total score
    char grade; // Grade letter
} Student;

// Function declarations
int compare_by_id(const void *a, const void *b);
int compare_by_last_name(const void *a, const void *b);
int compare_by_exam(const void *a, const void *b);
int compare_by_total(const void *a, const void *b);
void case3(Student *students, int studentCount);

#endif