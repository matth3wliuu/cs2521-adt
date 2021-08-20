#include <string.h>
#include <stdlib.h> 
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define Item char**

// * Polynomial Sorts
void bubbleSort(Item words, int start, int end);
void insertionSort(Item words, int start, int end);
void selectionSort(Item words, int start, int end);

// * Logarithm Sorts
void quickSort(Item words, int start, int end);
void mergeSort(Item words, int start, int end);

// * Helper Functions
void printSorted(Item words, int start, int end);
void freeItem(Item words, int size);

int cmpFunc(Item words, int a, int b);
