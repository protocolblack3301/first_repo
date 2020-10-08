#ifndef HELPER_H_INCLUDED
#define HELPER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

struct node *createnode(int data);
void sortedinsert(struct node **head,struct node *newnode);
void printlist(struct node *ptr);
int searchlist(struct node *ptr,int key);

struct node
{
    int data;
    struct node *next;
}*head=NULL;


int searchlist(struct node *ptr,int key){
while(ptr->next!=NULL){
      if(ptr->data==key){
            printf("key found\n");
        return 1;
      }

      ptr=ptr->next;
      }
    printf("key not found\n");

      return 0;
}

void printlist(struct node *ptr){
while(ptr->next!=NULL){
    printf("%d ",ptr->data);
    ptr=ptr->next;
}
printf("\n");
}


struct node *createnode(int num)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=num;
    ptr->next=NULL;
    return ptr;
};

void sortedinsert(struct node **head,struct node *newnode)
{
    if(*head==NULL)
    {
        *head=newnode;
    }
    else
    {
        struct node *preptr=*head;
        struct node *ptr=*head;

        while(ptr->next!=NULL&&(newnode->data > ptr->data))
        {
            preptr=ptr;
            ptr=ptr->next;
        }
         if(ptr==preptr){
                ptr->next=newnode;
            newnode->next=NULL;
        }
    else{


        preptr->next=newnode;

        newnode->next=ptr;
    }
    }


}


#endif // HELPER_H_INCLUDED
