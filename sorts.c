#include <string.h>
#include <stdlib.h> 
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#include <string.h>
#include <stdlib.h> 
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#include "sorts.h"

int cmp(const void *a, const void *b) {

    const char *str1 = (char *) a;
    const char *str2 = (char *) b;

    if (strcmp(str1, str2) < 0) return -1;
    if (strcmp(str1, str2) > 0) return 1;

    else return 0;

}

int cmpFunc(Item words, int a, int b) {
    
    char *str1 = words[a];
    char *str2 = words[b];

    if (strcmp(str1, str2) < 0) return -1;
    if (strcmp(str1, str2) > 0) return 1;

    else return 0;

}

static void swap(Item words, int a, int b) {

    char *temp = words[a];

    words[a] = words[b];

    words[b] = temp;
}

static void merge(Item words, int start, int mid, int end) {

    int i = start;
    int j = mid + 1;
    int k = 0;

    int nWords = end - start + 1;

    Item temp = calloc(nWords ,sizeof(char *));

    while (i <= mid && j < end) {

        if (cmpFunc(words, i, j) < 0) {

            temp[k++] = words[i++];
        }

        else {

            temp[k++] = words[j++];
        }

    }

    while (i <= mid) temp[k++] = words[i++];
    while (j < end) temp[k++] = words[j++];

    for (i = start, k = 0; i <= end; i++, k++) {

        words[i] = temp[k];
    }

    free(temp);

}

// * Polynomial Sorts
void bubbleSort(Item words, int start, int end) {

    int nSwaps; 

    for (int i = start; i < end; i++) {

        nSwaps = 0;

        for (int j = end - 1; j > start; j--) {
            
            if (cmpFunc(words, j, j - 1) < 0) {

                swap(words, j, j - 1);
                nSwaps++;
            }

        }

        if (nSwaps == 0) break;
    }

}

void insertionSort(Item words, int start, int end) {

    for (int i = start + 1; i < end; i++) {

        char *curr = words[i];
        
        int j;

        for (j = i - 1; j >= start; j--) {

            if (strcmp(words[j], curr) < 0) break;

            words[j + 1] = words[j];
        }

        words[j + 1] = curr;

        printSorted(words, start, end);

    }
}

void selectionSort(Item words, int start, int end);

// * Logarithm Sorts

void mergeSort(Item words, int start, int end) {

    int mid = (start + end) / 2;

    if (end <= start) return;

    mergeSort(words, start, mid);
    mergeSort(words, mid + 1, end);

    merge(words, start, mid, end);

}

void quickSort(Item words, int start, int end) {

    qsort(words[start], sizeof(char *), end - start - 1, cmp);

}

void printSorted(Item words, int start, int end) {

    printf("Sorted List: | ");

    for (int i = start; i < end; i++) {

        printf("%s | ", words[i]);

    }

    printf("\n");

}

void freeItem(Item words, int size) {

    for (int i = 0; i < size; i++) {

        free(words[i]);
    }

}
