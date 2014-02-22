#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct NODE {
    struct NODE *link;
    int value;
}Node;

int
sll_insert(Node **rootp, int new_value)
{

    Node *current;
    Node *previous;
    Node *new;


    current = *rootp;
    previous = NULL;

    while ( current != NULL && current->value < new_value) {
        previous = current;
        current = current->link;
    }

    new = (Node *)malloc( sizeof(Node) );
    if ( new == NULL ) {
        printf("malloc new node err! \n");
        return -1;
    }
    new->value = new_value;

    new->link = current;
    if ( previous == NULL ) {
        *rootp = new;
    } else {
        previous->link = new;
    }

    return 0;
}

int main(int argc, const char *argv[])
{
    Node *root;
    Node node;

    memset(&node, 0, sizeof(Node) ); 


    root = &node;
    root->link = NULL;
    root->value = 5;

    sll_insert(&root, 10);
    sll_insert(&root, 15);
    sll_insert(&root, 20);
    sll_insert(&root, 3);


    for(; root != NULL;) {
        printf("value->[%d] \n", root->value);
        root = root->link;
    }

    return 0;
}
