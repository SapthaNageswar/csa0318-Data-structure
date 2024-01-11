#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct HashTable {
    int table[SIZE];
    int count;
};

void initializeHashTable(struct HashTable *hashTable) {
    for (int i = 0; i < SIZE; i++) {
        hashTable->table[i] = -1; 
    }
    hashTable->count = 0;
}

int hashFunction(int key) {
    return key % SIZE;
}

int linearProbing(int key, int index) {
    return (index + 1) % SIZE;
}

void insert(struct HashTable *hashTable, int key) {
    if (hashTable->count == SIZE) {
        printf("Hash Table is full. Cannot insert %d.\n", key);
        return;
    }

    int index = hashFunction(key);

    while (hashTable->table[index] != -1) {
        index = linearProbing(key, index);
    }

    hashTable->table[index] = key;
    hashTable->count++;
}

void displayHashTable(struct HashTable *hashTable) {
    printf("Hash Table: ");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable->table[i] != -1) {
            printf("%d ", hashTable->table[i]);
        } else {
            printf("- ");
        }
    }
    printf("\n");
}

int main() {
    struct HashTable myHashTable;
    initializeHashTable(&myHashTable);

    insert(&myHashTable, 5);
    insert(&myHashTable, 15);
    insert(&myHashTable, 25);
    insert(&myHashTable, 7);
    insert(&myHashTable, 17);
    insert(&myHashTable, 27);

    displayHashTable(&myHashTable);

    return 0;
}

