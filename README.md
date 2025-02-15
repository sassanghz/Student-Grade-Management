# Student Management System - COMP 348

## Overview

The Student Grade Management System is a command-line application that manages student data. This program allows users to perform various operations such as displaying a grade spreadsheet, updating student information, sorting students by different criteria, and generating grade distributions.

## Options

- Display student grade spreadsheet
- Display grade distribution histogram
- Sort students by ID, last name, exam grade, or total grade
- Update student last names and exam grades
- Delete student records
- Load and save student data from/to a text file

## Prerequisites

- GCC (GNU Compiler Collection) to compile the code
- A terminal or command prompt for running the application
- Docker system

## Installation

1. Clone the repository/download the source code files .c and .h files and students.txt file
2. Navigate to the directory containing the files in root@f450614eefd2:/#

## Compilation

gcc -Wall -g spreadsheet.c ordering.c data.c calc.c -o spreadsheet
./spreadsheet

## Main Menu Options
1. Display Spreadsheet
2. Display Histogram
3. Set Sort Column
4. Update Last Name
5. Update Exam Grade
6. Update Grade Mapping
7. Delete Student
8. Exit

Select an Option: 
Enter the number corresponding to the desired action and press Enter.
Follow the prompts to complete the selected task.

## Exit the program
To exit the program, select option 8

## Data file
The program uses a data file named students.txt to store student records. Ensure that this file is in the same directory as the executable before running the program.

Each line represents a student record with the following fields:

Student ID
Last Name
First Name
Assignment 1 Score
Assignment 2 Score
Assignment 3 Score
Midterm Score
Exam Score

All rights reserved. 
@Author - Sassan Ghazi, 40226489#   S t u d e n t - G r a d e - M a n a g e m e n t 
 
 
