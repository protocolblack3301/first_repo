
#include "helper.h"
int hash(int key);
void insert(struct node* h[], int key);
void print(struct node* h[], int size);

void print(struct node* h[], int size)
{
    int i;
    for(i = 0; i < size; ++i) {
	if(h[i] != NULL) {
	    printlist(h[i]);
	}
    }
}

int hash(int key)
{
    return (key % 10);
}

void insert(struct node* h[], int key)
{
    int index = hash(key);
    struct node* newnode = createnode(key);
    sortedinsert(&(h[index]), newnode);
}

int main()
{

    struct node* ht[10];
    int i;
    for(i = 0; i < 10; ++i) {
	ht[i] = NULL;
    }

    insert(ht, 12);
    insert(ht, 22);
    insert(ht, 32);
    insert(ht, 42);
    searchlist(ht[hash(22)], 22);

    print(ht, 10);

    return 0;
}
