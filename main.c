#include <stdio.h>
#include <pthread.h>
#include "./files/file_management.h"
#include "./threads/threads.h"
#include <stdlib.h>

#define THREADS 5

pthread_mutex_t mutex;
int sum = 0;

/*for vectors
int *vector;

typedef struct
{
    int jump;
    int startFrom;
} Data;

void *routine(void *arg)
{
    Data *data = (Data *)arg;
    printf("Thread %ld: %d\n", pthread_self(), data->startFrom);
    for (int i = data->startFrom; i < data->startFrom + data->jump; i++)
    {
        pthread_mutex_lock(&mutex);
        sum += vector[i];
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}*/


typedef struct{
    int jump;
    int startX;
    int limit;
} Data;

int **matrix;

void *routine(void *arg){
    Data *data = (Data *)arg;
    printf("Thread %ld: %d\n", pthread_self(), data->startX);
    for (int i = data->startX; i < data->startX + data->jump; i++)
    {
        for (int j = 0; j < data->limit; j++)
        {
            pthread_mutex_lock(&mutex);
            sum += matrix[i][j];
            pthread_mutex_unlock(&mutex);
        }
    }
    return NULL;
}


int main(int argc, char **argv)
{
    pthread_t thread[THREADS];
    //int vectorLimit;
    //generateVectorFile(10000000, "vector.txt");
    //vector = generateVectorFromFile("vector.txt", &vectorLimit);
    // showVector(vector, vectorLimit);
    int limit;
    generateSquareMatrixFile(1000, "matrix.txt");
    matrix = generateSquareMatrixFromFile("matrix.txt", &limit);
    showSquareMatrix(matrix, limit);
    for (int i = 0; i < THREADS; i++)
    {
        /*Data *arg = malloc(sizeof(Data));
        arg->jump = vectorLimit/THREADS;
        arg->startFrom = i * arg->jump;
        pthread_create(&thread[i], NULL, routine, (void *)arg);*/
        Data *arg = malloc(sizeof(Data));
        arg->jump = limit/THREADS;
        arg->startX = i * arg->jump;
        arg->limit = limit;
        pthread_create(&thread[i], NULL, routine, (void *)arg);
    }
    for (int i = 0; i < THREADS; i++)
    {
        pthread_join(thread[i], NULL);
    }
    printf("Sum: %d\n", sum);
    getchar();
    return 0;
}
