#include <stdio.h>
#include <stdlib.h>

#define SIZEOFTABLE 10
#define NEWSIZEOFTABLE 20

typedef struct {
    int key;
    int isOccupied;
} HashNode;

typedef struct {
    HashNode *table;
    int size;
} HashTable;

int hashFunction(int key, int size) {
    return key % size;
}


void insertLinearProbing(HashTable *hashTable, int key) {
    int index = hashFunction(key, hashTable->size);
    while (hashTable->table[index].isOccupied) {
        index = (index + 1) % hashTable->size;
    }
    hashTable->table[index].key = key;
    hashTable->table[index].isOccupied = 1;
}

void displayTable(HashTable *hashTable) {
    for (int i = 0; i < hashTable->size; i++) {
        printf("%d: %d\n", i, hashTable->table[i].key);
    }
    printf("\n");
}

void rehash(HashTable *oldTable, HashTable *newTable, int newSize) {
    initializeTable(newTable, newSize);

    for (int i = 0; i < oldTable->size; i++) {
        if (oldTable->table[i].isOccupied) {
            insertLinearProbing(newTable, oldTable->table[i].key);
        }
    }
}
void initializeTable(HashTable *hashTable, int size) {
    hashTable->size = size;
    hashTable->table = (HashNode *)malloc(size * sizeof(HashNode));
    for (int i = 0; i < size; i++) {
        hashTable->table[i].key = 0;
        hashTable->table[i].isOccupied = 0;
    }
}
