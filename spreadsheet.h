#ifndef SPREADSHEET_H
#define SPREADSHEET_H
#define MAX_STUDENTS 100

#include "ordering.h"
#include "data.h"
#include "calc.h"

void spreadsheet(int num, char grade[], Student *students, char *fields[][8], int studentCount);

#endif