#ifndef FILE_MANAGEMENT_H
#define FILE_MANAGEMENT_H
#include <stdio.h>

void error(const char *message);

int readVectorLimit(FILE *file);
int* readMatrixLimit(FILE *file);

void showVector(const int *vector, const int limit);
void showSquareMatrix(int **matrix, const int limit);
void showCustomMatrix(int **matrix, const int rows, const int columns);

void generateVectorFile(const int limit, const char *name);
void generateSquareMatrixFile(const int limit, const char *name);
void generateCustomMatrixFile(const int rows, const int columns);
int* generateVectorFromFile(const char *filename, int* limit);
int** generateSquareMatrixFromFile(const char *filename, int* limit);
int** generateCustomMatrixFromFile(const char *filename, int* rows, int* columns);

#endif //FILE_MANAGEMENT_H
