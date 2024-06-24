#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

struct HashNode {
    char key[20];
    int value;
};

struct HashTable {
    struct HashNode* nodes[SIZE];
};

int hashFunction(char key[]) {
    int hash = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hash += key[i];
    }
    return hash % SIZE;
}

void insert(struct HashTable* table, char key[], int value) {
    int index = hashFunction(key);

    while (table->nodes[index] != NULL) {
        if (strcmp(table->nodes[index]->key, key) == 0) {
            // Update value if key already exists
            table->nodes[index]->value = value;
            return;
        }

        // Linear probing
        index = (index + 1) % SIZE;
    }

    // Insert new key-value pair
    struct HashNode* newNode = (struct HashNode*)malloc(sizeof(struct HashNode));
    strcpy(newNode->key, key);
    newNode->value = value;
    table->nodes[index] = newNode;
}

int search(struct HashTable* table, char key[]) {
    int index = hashFunction(key);

    while (table->nodes[index] != NULL) {
        if (strcmp(table->nodes[index]->key, key) == 0) {
            // Return the corresponding value if key is found
            return table->nodes[index]->value;
        }

        // Linear probing
        index = (index + 1) % SIZE;
    }

    // Key not found
    return -1;
}

int main() {
    struct HashTable hashTable;

    // Initialize nodes to NULL
    for (int i = 0; i < SIZE; i++) {
        hashTable.nodes[i] = NULL;
    }

    // Example Usage
    insert(&hashTable, "apple", 5);
    insert(&hashTable, "orange", 8);

    printf("Value for 'apple': %d\n", search(&hashTable, "apple"));   // Output: 5
    printf("Value for 'banana': %d\n", search(&hashTable, "banana")); // Output: -1

    getch();
    return 0;
}