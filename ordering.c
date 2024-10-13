#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ordering.h"

// functions to do the sorting comparisions
// id function
int compare_by_id(const void *a, const void *b) {
    const Student *studentA = (const Student *)a;
    const Student *studentB = (const Student *)b;
    return studentA->id - studentB->id; // Compare by ID
}

int compare_by_last_name(const void *a, const void *b) {
    const Student *studentA = (const Student *)a;
    const Student *studentB = (const Student *)b;
    return strcmp(studentA->lastName, studentB->lastName); // Compare by Last Name
}

int compare_by_exam(const void *a, const void *b) {
    const Student *studentA = (const Student *)a;
    const Student *studentB = (const Student *)b;
    return (studentB->scores[4] - studentA->scores[4]); // Compare by Exam score
}

int compare_by_total(const void *a, const void *b) {
    const Student *studentA = (const Student *)a;
    const Student *studentB = (const Student *)b;
    return studentB->total - studentA->total; // Compare by Total score
}

// function to do the sorting order
void case3(Student *students, int studentCount) {
    printf("Column Options\n");
    printf("--------------\n");
    printf("1. Student ID\n");
    printf("2. Last name\n");
    printf("3. Exam\n");
    printf("4. Total\n");

    printf("\nSort Column: ");
    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            qsort(students, studentCount, sizeof(Student), compare_by_id);
            printf("\nSort column updated\n");
            break;
        case 2:
            qsort(students, studentCount, sizeof(Student), compare_by_last_name);
            printf("\nSort column updated\n");
            break;
        case 3:
            qsort(students, studentCount, sizeof(Student), compare_by_exam);
            printf("\nSort column updated\n");
            break;
        case 4:
            qsort(students, studentCount, sizeof(Student), compare_by_total);
            printf("\nSort column updated\n");
            break;
        default:
            printf("\nInvalid choice. Keeping current sort order.\n");
    }
}
