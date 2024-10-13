#include <stdio.h>
#include <stdlib.h>
#include "calc.h"
#include "data.h"

int gradeA = 80;
int gradeB = 70;
int gradeC = 60;
int gradeD = 50;

void calculateCase1(char *fields[], int *grade_total, char *grade_letter) {
    int A1 = atoi(fields[3]);
    int A2 = atoi(fields[4]);
    int A3 = atoi(fields[5]);
    int midterm = atoi(fields[6]);
    int exam = atoi(fields[7]);

    float totalScore = (((A1 + A2 + A3) / 120.0f) * 0.25f) + ((midterm / 25.0f) * 25.0f) + ((exam / 40.0f) * 50.0f);
    *grade_total = (int)totalScore;

    if (*grade_total >= gradeA) {
        *grade_letter = 'A';
    } else if (*grade_total >= gradeB) {
        *grade_letter = 'B';
    } else if (*grade_total >= gradeC) {
        *grade_letter = 'C';
    } else if (*grade_total >= gradeD) {
        *grade_letter = 'D';
    } else {
        *grade_letter = 'F';
    }
}

// Other calculation functions (like countGrades, updateGradeMap, etc.) go here
void updateGradeMap(){

    // Display current grade mappings
    printf("\nCurrent Mapping: ");
    printf("\nA: >= %d", gradeA);
    printf("\nB: >= %d", gradeB);
    printf("\nC: >= %d", gradeC);
    printf("\nD: >= %d", gradeD);
    printf("\nF:  < %d", gradeD);

    // Read new grade mappings from the user
    printf("\n\nEnter new A baseline: ");
    scanf("%d", &gradeA);
    getchar();

    printf("\nEnter new B baseline: ");
    scanf("%d", &gradeB);
    getchar();

    printf("\nEnter new C baseline: ");
    scanf("%d", &gradeC);  // Make sure you use %d here
    getchar();

    printf("\nEnter new D baseline: ");
    scanf("%d", &gradeD);  // Corrected to %d for integers
    getchar();

    // Display new grade mappings
    printf("\nNew Mapping:");
    printf("\nA: >= %d", gradeA);
    printf("\nB: >= %d", gradeB);
    printf("\nC: >= %d", gradeC);
    printf("\nD: >= %d", gradeD);
    printf("\nF:  < %d\n", gradeD);  // F is less than the D baseline
}

void case2(char grade[]){

        int countA = 0, countB = 0, countC = 0, countD = 0, countF = 0;
        countGrades(grade, &countA, &countB, &countC, &countD, &countF);
        displayGradeDis(countA, countB, countC, countD, countF);
}

void displayGradeDis(int countA, int countB, int countC, int countD, int countF){

        printf("\nA: ");
        for(int i = 0; i < countA; i++){
                printf("*");
        }
        printf("\n");

        printf("B: ");
        for(int i = 0; i < countB; i++){
                printf("*");
        }
        printf("\n");

        printf("C: ");
        for(int i = 0; i < countC; i++){
                printf("*");
        }
        printf("\n");

        printf("D: ");
        for(int i = 0; i < countD; i++){
                printf("*");
        }
        printf("\n");

        printf("F: ");
        for(int i = 0; i < countF; i++){
                printf("*");
        }
        printf("\n");
}

void countGrades(char grade[], int *countA, int *countB, int *countC, int *countD, int *countF){

        for (int i = 0; i < MAX_STUDENTS; i++) {
            switch (grade[i]) {
                case 'A': (*countA)++; break;
                case 'B': (*countB)++; break;
                case 'C': (*countC)++; break;
                case 'D': (*countD)++; break;
                case 'F': (*countF)++; break;
            }
        }

}