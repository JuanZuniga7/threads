#include "file_management.h"
#include <stdio.h>
#include <stdlib.h>

void error(const char *message) {
    printf("Error: %s\n", message);
    exit(EXIT_FAILURE);
}

int readVectorLimit(FILE *file) {
    int limit;
    fscanf(file, "%d", &limit);
    return limit;
}

int* readMatrixLimit(FILE *file) {
    int* limit;
    limit = (int*)malloc(2 * sizeof(int));
    fscanf(file, "%d", &limit[0]);
    fscanf(file, "%d", &limit[1]);
    return limit;
}

void showVector(const int *vector, const int limit) {
    for (int i = 0; i < limit; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
}

void showSquareMatrix(int **matrix, const int limit) {
    for (int i = 0; i < limit; i++) {
        for (int j = 0; j < limit; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void showCustomMatrix(int **matrix, const int rows, const int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void generateVectorFile(const int limit, const char *name) {
    FILE *file = fopen(name, "w");
    if (file == NULL) {
        error("Could not open file");
    }
    fprintf(file, "%d\n", limit);
    for (int i = 0; i < limit; i++) {
        fprintf(file, "%d\n", rand() % 100);
    }
    fclose(file);
}

void generateSquareMatrixFile(const int limit, const char *name) {
    FILE *file = fopen(name, "w");
    if (file == NULL) {
        error("Could not open file");
    }
    fprintf(file, "%d\n", limit);
    fprintf(file, "%d\n", limit);
    for (int i = 0; i < limit; i++) {
        for (int j = 0; j < limit; j++) {
            fprintf(file, "%d ", rand() % 100);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

void generateCustomMatrixFile(const int rows, const int columns) {
    FILE *file = fopen("matrix.txt", "w");
    if (file == NULL) {
        error("Could not open file");
    }
    fprintf(file, "%d\n%d\n", rows, columns);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            fprintf(file, "%d ", rand() % 100);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

int* generateVectorFromFile(const char* filename, int *limit){
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        error("Could not open file");
    }
    int size = readVectorLimit(file);
    int *vector = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        fscanf(file, "%d", &vector[i]);
    }
    fclose(file);
    *limit = size;
    return vector;
}

int** generateSquareMatrixFromFile(const char* filename, int *limit){
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        error("Could not open file");
    }
    int *size = readMatrixLimit(file);
    int **matrix = (int**)malloc(size[0] * sizeof(int*));
    for (int i = 0; i < size[0]; i++) {
        matrix[i] = (int*)malloc(size[1] * sizeof(int));
        for (int j = 0; j < size[1]; j++) {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }
    fclose(file);
    *limit = size[0];
    return matrix;
}

int** generateCustomMatrixFromFile(const char* filename, int* rows, int* columns){
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        error("Could not open file");
    }
    int *limit = readMatrixLimit(file);
    int **matrix = (int**)malloc(limit[0] * sizeof(int*));
    for (int i = 0; i < limit[0]; i++) {
        matrix[i] = (int*)malloc(limit[1] * sizeof(int));
        for (int j = 0; j < limit[1]; j++) {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }
    fclose(file);
    return matrix;
}
