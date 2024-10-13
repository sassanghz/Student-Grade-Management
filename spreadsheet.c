#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordering.h"
#include "data.h"
#include "calc.h"

#define MAX_STUDENTS 100
#define STUDENTS 100

void spreadsheet(int num, char grade[], Student *students, char *fields[][8], int studentCount) {

    switch (num) {
        case 1:
            case1(grade, fields, &studentCount);  //&studentCount
            break;
        case 2:
            printf("\n\nCOMP 348 GRADE DISTRIBUTION");
            case2(grade);  // Calling the case2 function to display the grade distribution
            break;
        case 3:
            printf("\n\nColumn Options\n");
            case3(students, studentCount);// studentCount
            break;
        case 4:
            case1(grade, fields, &studentCount);
            updateLastName();
            break;
        case 5:
            case1(grade, fields, &studentCount);
            updateExamGrade(fields, studentCount);
            break;
        case 6:
            updateGradeMap();
            break;
        case 7:
            case1(grade, fields, &studentCount);
            deleteStudent(fields, &studentCount);
            break;
        case 8:
            printf("Goodbye and thanks for using our spreadsheet app.\n");
            break;
        default:
            printf("Invalid Selection! Please choose a valid option.\n");
    }

    printf("Press 'c' or 'C' to continue...");
    getchar();  // Wait for user to press Enter before re-displaying the menu
}

int main(void) {
    char grade[MAX_STUDENTS];
    memset(grade, 0, sizeof(grade)); // Initialize grade array

    char *fields[MAX_STUDENTS][8];
    int studentCount = 0; // Initialize studentCount

    Student students[MAX_STUDENTS]; // Declare the students array
    int num;

    do {
        clearScreen();  // Clear the screen before displaying the menu

        printf("Spreadsheet Menu\n");
        printf("----------------\n");
        printf("1. Display Spreadsheet\n");
        printf("2. Display Histogram\n");
        printf("3. Set Sort Column\n");
        printf("4. Update Last Name\n");
        printf("5. Update Exam Grade\n");
        printf("6. Update Grade Mapping\n");
        printf("7. Delete Student\n");
        printf("8. Exit\n");

        printf("Selection: ");
        scanf("%d", &num);  // Get user input

        while (getchar() != '\n');  // Clear the input buffer

        spreadsheet(num, grade, students, fields, studentCount);  // Call the spreadsheet function based on user input

    } while (num != 8);  // Loop until the user chooses to exit

    return 0;
}
