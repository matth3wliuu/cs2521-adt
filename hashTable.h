
// * Linear Probing HashTable ADT

typedef struct HashTableRep {
    char **items;
    int size; 
    int nItems;
} HashTableRep;

typedef struct HashTableRep *HashTable;

HashTable hashTableCreate(int size);

int hash(char *key, int size);

void hashInsert(HashTable hTable, char *item);

char *hashGet(HashTable hTable, char *key);

void hashDelete(HashTable hTable, char *key);

void freeHashTable(HashTable hTable);

void displayHashTable(HashTable hTable);

