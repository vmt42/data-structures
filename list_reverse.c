#include <stdio.h>
#include <stdlib.h>

#undef DEBUG

typedef struct List ListType;

struct List {
    ListType *next;
    int i;
};

void print_list(ListType *head) {
    if (!head) 
        return;

    printf("%d\n", head->i);
    print_list(head->next);
}

ListType* create_lep(int i) {
    ListType *lep = (ListType*) malloc(sizeof(ListType));

    lep->i = i;
    lep->next = (ListType*) 0;
}

#define LIST_SIZE 10 // must be > 0

ListType* gen_list(void) {
    ListType *head,
             *cur_lep,
             *next_lep;
    int i;

    head = create_lep(10);

    cur_lep = head;
    for (i = 1; i < LIST_SIZE ; i++) { 
        next_lep = create_lep(i + 10);

        cur_lep->next = next_lep;
        cur_lep = next_lep;
    }

    return head;
}

ListType* reverse_list_recursive(ListType *head) {
// TODO: implement this function
}

ListType* reverse_list_iterative(ListType *head) {
// TODO: implement this function

    ListType  *cur,
              *prev,
              *next;

    if (!head || !head->next) // lazy evaluation (?)
//    if (!head->next || !head) // wrong!!!
        return head;

    prev = head;
    cur = head->next;
    head->next = 0;

    for (;;) {
#ifdef DEBUG
        printf("DEBUG cur->i = %d\n", cur->i);
#endif
        next = cur->next;
        cur->next = prev;

        if (!next) break;

        prev = cur;
        cur = next;
    }
#ifdef DEBUG
    printf("DEBUG cur->next = %llu\n", (long long unsigned int) cur->next);
#endif

    return cur;
}

void main(void) {

    ListType *head = gen_list(); 

    print_list(head);

    head = reverse_list_recursive(head);

    printf("-----\n");
    print_list(head);

    head = reverse_list_iterative(head);

    printf("-----\n");
    print_list(head);

    reverse_list_iterative(0);
}

