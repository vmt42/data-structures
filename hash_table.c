#include <stdio.h>


#define MAX_HASH_VAL

typedef struct ElementStruct {
    char key[KEY_SIZE];
    char data[DATA_SIZE];
} Element;

int hash(char* key);

Element* lookup(HashTable* hash_table, char* key);
Element* delete(HashTable* hash_table, char* key);
Element* insert(HashTable* hash_table, Element* elem);

HashTable* init_hash_table(/* ??? */)

void main(void) {



}

