#include <string.h>
#include <stdlib.h> 
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#include "heap.h"
#include "tree.h"

// * API to a max-heap
// * => every parernt > children

Heap heapCreate(int size) {

    Heap toReturn = malloc(sizeof(HeapRep));
    toReturn->items = calloc(sizeof(int), size);
    toReturn->currSize = 0;
    toReturn->maxSize = size;

    return toReturn;
}

static void swapPos(char *arr, int a, int b) {

    char temp = arr[a];

    arr[a] = arr[b];
    arr[b] = temp;
}

// when inserting 
static void fixUp(char *arr, int currPos) {

    while (currPos > 1 && (arr[currPos] > arr[currPos / 2]) ) {

        swapPos(arr, currPos, currPos / 2);

        currPos = currPos / 2;
    }
}

// when extracting
// every child is less than their parent
static void fixDown(char *arr, int index, int maxSize) {

    while (2 * index <= maxSize) {

        int i = 2 * index;

        char leftChild = arr[i];
        char rightChild = arr[i + 1];

        // find larger child
        if (rightChild > leftChild && i < maxSize) i++;

        // if child < parent then no more swapping required
        if (arr[i] < arr[index]) break;
        
        // if parent > child, swap their indices
        swapPos(arr, index, i);
        
        // move to the child
        index = i;
    }
}

void heapInsert(Heap h, char item) {

    h->currSize++;

    h->items[h->currSize] = item;

    fixUp(h->items, h->currSize);
}

char heapExtract(Heap h) {

    char extracted = h->items[1];

    h->items[1] = h->items[h->currSize];
    h->currSize--;

    fixDown(h->items, 1, h->currSize);

    return extracted;
}

void heapSort(char *arr, int size) {

    Heap h = heapCreate(size);

    // construct the max heap
    for (int i = 0; i < size; i++) {

        heapInsert(h, arr[i]);
    }

    heapDisplay(h);

    while (h->currSize > 0) {

        char extracted = heapExtract(h);

        arr[size - 1] = extracted;
        size--;
       
    } 

}

void displayArray(char *arr, int size) {

     for (int i = 0; i < size; i++) {
        printf("%c -> ", arr[i]);
    }

    printf("X\n");

}

void heapDisplay(Heap h) {

    // index 0 is empty 
    for (int i = 1; h->items[i] != '\0' && i <= h->currSize; i++) {

        printf("%c -> ", h->items[i]);
    }

    printf("X \n");
}
