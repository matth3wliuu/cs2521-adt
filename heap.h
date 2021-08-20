#include <string.h>
#include <stdlib.h> 
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

typedef struct HeapRep {
    char *items;
    int currSize;
    int maxSize;
} *Heap;

Heap heapCreate(int size);

void heapInsert(Heap h, char item);

char heapExtract(Heap h);

void heapSort(char *arr, int size);

void heapDisplay(Heap h);

void displayArray(char *arr, int size);

