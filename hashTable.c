// * Implementation of a Linear Probing Hash Table 

#include <string.h>
#include <stdlib.h> 
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#include "hashTable.h"

HashTable hashTableCreate(int size) {

    HashTable hTable = malloc(sizeof(HashTableRep));
    hTable->items = calloc(size, sizeof(char *));
    hTable->nItems = 0;
    hTable->size = size;

    return hTable;
}

// Universal hashing function
int hash(char *key, int size) {

    int h = 0; 
    int a = 31415;
    int b = 21783;

    char *c;
    for (c = key; *c != '\0'; c++) {
        a = a * b % (size - 1 );
        h = (a * h + *c) % size;
    }

    return h;
}

void hashInsert(HashTable hTable, char* item) {

    int size = hTable->size;
    char *key = item;
    char **arr = hTable->items;

    int hashed = hash(key, size);

    for (int i = 0; i < size; i++) {

        if (arr[hashed] == NULL) break;

        if (strcmp(key, arr[hashed]) == 0) break;

        hashed = (hashed + 1) % size;
    }

    if (arr[hashed] == NULL) hTable->nItems++;

    if (arr[hashed] != NULL) free(arr[hashed]);

    arr[hashed] = item;
    
}

char *hashGet(HashTable hTable, char *key) {

    int size = hTable->size;
    int hashed = hash(key, size);
    char **arr = hTable->items;

    for (int i = 0; i < size; i++) {
        
        if (arr[hashed] == NULL) break;

        if (strcmp(key, arr[hashed]) == 0) return arr[hashed];

        hashed = (hashed + 1) % size;
    }

    return NULL;
}

void hashDelete(HashTable hTable, char *key) {

    int size = hTable->size;
    char **arr = hTable->items;
    int hashed = hash(key, size);

    for (int i = 0; i < size; i++) {
        
        // key not in the table
        if (arr[hashed] == NULL) return; 

        // key is in table
        if (strcmp(arr[hashed], key) == 0) break;
        
        // key has not been reached yet 
        hashed = (hashed + 1) % size;
    }

    arr[hashed] = NULL;
    hTable->nItems--;

    hashed = (hashed + 1) % size;
    
    while (arr[hashed] != NULL) {

        // remove item from table
        char *item = arr[hashed];
        printf("removing = %s \n", item);

        arr[hashed] = NULL;
        hTable->nItems--;

        // re-insert into table 
        hashInsert(hTable, item);

        hashed = (hashed + 1) % size;
    }

}

void displayHashTable(HashTable hTable) {

    for (int i = 0; i < hTable->size; i++) {

        printf("| %s ", hTable->items[i]);
    }

    printf("|\n");
}

void freeHashTable(HashTable hTable);

