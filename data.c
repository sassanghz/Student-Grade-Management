#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calc.h"

#define MAX_STUDENTS 100
#define LINE_LENGTH 256

void clearScreen() {
    system("clear");  // Clear the screen on Linux/Docker
}

void case1(char grade[], char *fields[][8], int *studentCount) {


    FILE *file = fopen("students.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file\n");
        return;
    }

    char line[350];
    printf("\n\nCOMP 348 GRADE SHEET\n\n");
    printf("%-10s %-15s %-15s %-5s %-5s %-5s %-7s %-7s %-7s %-7s\n",
           "ID", "Last", "First", "A1", "A2", "A3", "Midterm", "Exam", "Total", "Grade");
    printf("---------------------------------------------------------------------------------------------\n");

    int i = 0; // keeping track of students
    while (fgets(line, sizeof(line), file) && i < MAX_STUDENTS) {
        line[strcspn(line, "\n")] = 0;  // Remove newline character

        char *token = strtok(line, "|");
        //char *fields[8];  // 8 fields in the text file

        // Initialize all fields to NULL

        for (int j = 0; j < 8; j++) {
           fields[i][j] = NULL;
        }

        // Tokenizing the line into exactly 8 fields
        //printf("Tokenizing line: %s\n", line);  // DEBUG
        int j = 0;
        while (token != NULL && j < 8) {
            //fields[j] = token;
            fields[i][j] = strdup(token);
            //printf("Token %d: %s\n", i, token);  // DEBUG
            token = strtok(NULL, "|");
            j++;
        }

        // Ensure that exactly 8 fields were parsed
        if (j == 8) {
            /*printf("Fields: %s %s %s %s %s %s %s %s\n",
                   fields[0], fields[1], fields[2], fields[3],
                   fields[4], fields[5], fields[6], fields[7]);*/
            int grade_total;
            char grade_letter;

            // Call function to calculate total and grade
            calculateCase1(fields[i], &grade_total, &grade_letter);

            // Print the output
            printf("%-10s %-15s %-15s %-5s %-5s %-5s %-7s %-7s %-7d %-7c\n",
                   fields[i][0], fields[i][1], fields[i][2], fields[i][3],
                    fields[i][4], fields[i][5], fields[i][6], fields[i][7], grade_total, grade_letter);

            grade[i] = grade_letter;
            i++;

        } else {
            printf("Error: Incorrect number of fields in the line\n");
        }
        (*studentCount)++;

    }
    fclose(file);
}

// Other data management functions (like deleteStudent, updateExamGrade, etc.) go here
void updateLastName(){

        //case1(grade, fields, &studentCount);

        int idUpdate;
        char lastNameUpdate[30];

        printf("\n\nEnter Student ID: ");
        scanf("%d", &idUpdate);
        getchar();

        printf("\nEnter updated Last Name: ");
        fgets(lastNameUpdate, sizeof(lastNameUpdate), stdin);
        lastNameUpdate[strcspn(lastNameUpdate, "\n")] = 0;

        FILE *file = fopen("students.txt", "r");
        if(file == NULL){
                printf("Error: could not open file\n");
                return;
        }

        //array to store updated data
        char lines[MAX_STUDENTS][LINE_LENGTH];
        int i = 0;
        int foundID = 0;

        //read the file content
        while(fgets(lines[i], sizeof(lines[i]), file)){
                int id;
                sscanf(lines[i], "%d", &id);

                if(id == idUpdate){
                        foundID = 1;

                        char updateLine[LINE_LENGTH];
                        char *token;
                        char temp[LINE_LENGTH];

                        strcpy(temp, lines[i]);

                        token = strtok(temp, "|");
                        snprintf(updateLine, sizeof(updateLine), "%d|", id);

                        int fieldCount = 0;
                        while(token != NULL){
                                token = strtok(NULL, "|");
                                fieldCount++;

                                if(fieldCount == 1){
                                        strcat(updateLine, lastNameUpdate);
                                }else if (token != NULL){
                                        strcat(updateLine, "|");
                                        strcat(updateLine, token);
                                }
                        }
                        strcpy(lines[i], updateLine);
                }
                i++;
        }

        fclose(file);

        file = fopen("students.txt", "w");// writing the updated last name to the file
        if(file == NULL){
                printf("Error: could not open file for writing\n");
                return;
        }

        for(int j = 0; j < i; j++){
                fputs(lines[j], file);
        }

        fclose(file);// closing the file

        if(foundID){
                printf("Last name updated\n");
        }else{
                printf("Student ID not found.\n");
        }
}

void updateExamGrade(char *fields[][8], int studentCount){

    int idUpdate;
    printf("\n\nEnter Student ID: ");
    scanf("%d", &idUpdate);
    while (getchar() != '\n'); // Clear the input buffer

    int found = 0; // Flag to track if the student ID was found
    for (int i = 0; i < studentCount; i++) {
        if (atoi(fields[i][0]) == idUpdate) { // Check if the ID matches
            found = 1; // Set the flag to found

            int newExamGrade;
            printf("\nEnter updated exam grade: ");
            scanf("%d", &newExamGrade);
            while (getchar() != '\n'); // Clear the input buffer

            // Update the in-memory fields array for the exam grade
            snprintf(fields[i][7], 3, "%d", newExamGrade); // Update the exam grade in fields
            printf("\nExam grade updated\n");

            // Recalculate total grade and grade letter
            int grade_total;
            char grade_letter;
            calculateCase1(fields[i], &grade_total, &grade_letter); // Calculate the new grades

            // Display updated total and letter grade to the user
            //printf("Updated Total Grade: %d, Letter Grade: %c\n", grade_total, grade_letter);

            // Now write back to the file, excluding the total and letter grade
            FILE *file = fopen("students.txt", "r+"); // Open for reading and writing
            if (file == NULL) {
                     printf("Error: could not open file\n");
                return;
            }

            // Read the lines into memory
            char lines[MAX_STUDENTS][LINE_LENGTH];
            int j = 0;
            while (fgets(lines[j], sizeof(lines[j]), file) && j < MAX_STUDENTS) {
                j++;
            }

            // Rewrite the file with updated exam grade
            rewind(file); // Go back to the start of the file
            for (int k = 0; k < j; k++) {
                int fileId;
                sscanf(lines[k], "%d", &fileId); // Read the ID from the line

                // If it's the student being updated, rewrite their line
                if (fileId == idUpdate) {
                    snprintf(lines[k], sizeof(lines[k]),
                             "%s|%s|%s|%s|%s|%s|%s|%d\n",
                             fields[i][0], fields[i][1], fields[i][2], fields[i][3],
                             fields[i][4], fields[i][5], fields[i][6], newExamGrade);
                }
                fprintf(file, "%s", lines[k]); // Write back the line
            }

            fclose(file); // Close the file
            break; // Exit the loop as the student has been found
        }
    }

    if (!found) {
        printf("Student ID not found\n"); // Inform user if the ID was not found
    }


}

void deleteStudent(char *fields[][8], int *studentCount) {
    int idToDelete;
    printf("Enter Student ID: ");
    scanf("%d", &idToDelete);

    // Find the student in the list
    int found = 0;
    for (int i = 0; i < *studentCount; i++) {
        if (atoi(fields[i][0]) == idToDelete) {
            found = 1;
            printf("Student with ID %d found. Deleting...\n", idToDelete);

            // Shift remaining students up to overwrite the deleted student
            for (int j = i; j < *studentCount - 1; j++) {
                for (int k = 0; k < 8; k++) {
                    fields[j][k] = fields[j + 1][k];
                }
            }
            (*studentCount)--;  // Decrease the student count
            //printf("Student successfully deleted from memory\n");
            //break;
        }
    }

    if (!found) {
        printf("Student ID not found.\n");
        return;  // Exit if student not found
    }

    // Step 2: Rewrite the text file without the deleted student
    FILE *file = fopen("students.txt", "w");  // Open the file in write mode
    if (!file) {
        printf("Error opening the file.\n");
        return;
    }

    // Write the remaining students back to the file
    for (int i = 0; i < *studentCount; i++) {
        fprintf(file, "%s|%s|%s|%s|%s|%s|%s|%s\n",
                fields[i][0], fields[i][1], fields[i][2],
                fields[i][3], fields[i][4], fields[i][5],
                fields[i][6], fields[i][7]);
    }

    fclose(file);  // Close the file
    printf("Student successfully deleted.\n");
}
