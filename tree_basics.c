#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_WORD_SIZE 100

typedef struct Leaf LeafType;

struct Leaf {
    LeafType *less;
    LeafType *more;
//---
    char word[MAX_WORD_SIZE];
};

void main(void) {
//    LeafType la[1000];
    LeafType root = {0, 0, ""};
    int read = 1;

    while (read) {
        root.less = (LeafType*) malloc(sizeof(LeafType));
        root.less->less = 0;
        root.less->more = 0;
        strcpy(root.less->word, "new-word");

        read = 0;
    }
}
