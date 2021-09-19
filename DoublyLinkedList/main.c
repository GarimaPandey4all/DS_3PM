#include <stdio.h>
#include <stdlib.h>

struct node {

    struct node *prev;
    int info;
    struct node *next;
};

struct node *start = NULL;

struct node *createNode()
{
    struct  node *n;

    n = (struct node *)malloc(sizeof(struct node));

    return n;
};

//insert at start position only once
void insertAtStart() {

    struct node *temp;

    if(start == NULL)
    {
        temp = createNode();

        temp->prev = NULL;

        printf("Enter any value:");
        scanf("%d", &temp->info);

        temp->next = NULL;

        start = temp;
    }
    else {
        printf("List has some nodes");
    }
}

void insertAtLast()
{
    struct node *temp, *t;

    temp = createNode();

    printf("Enter any value:");
    scanf("%d", &temp->info);

    temp->next = NULL;

    if(start == NULL)
    {
        temp->prev = NULL;
        start = temp;
    }
    else {
        t = start;

        while(t->next != NULL)
        {
            t = t->next;
        }

        temp->prev = t;
        t->next = temp;
    }
}

void insertAfterNode()
{
    struct node *temp, *ptr;

    ptr = searchNode();

    if(ptr == NULL)
    {
        printf("List is Empty. Invalid Search");
    }
    else {
        temp = createNode();

        printf("Enter any value:");
        scanf("%d", &temp->info);

        temp->prev = ptr;
        temp->next = ptr->next;

        if(ptr->next != NULL)
        {
            ptr->next->prev = temp;
        }

        ptr->next = temp;
    }
}

void viewList()
{
    struct node *t;

    if(start == NULL)
    {
        printf("List is Empty");
    }
    else {
        t = start;

        while(t != NULL)
        {
            printf("%d", t->info);
            t = t->next;
        }
    }
}

void deleteFirstNode()
{
    struct node *t;

    if(start == NULL)
    {
        printf("List is Empty");
    }
    else {
        t = start;

        start = start->next;
        start->prev = NULL;

        free(t);
    }
}

void deleteLastNode()
{
    struct node *t;

    if(start == NULL)
    {
        printf("List is Empty");
    }
    else {
        t = start;

        while(t->next != NULL)
        {
            t = t->next;
        }

        if(start->next == NULL)
        {
            start = NULL;
        }
        else {
            t->prev->next = NULL;
        }
    }
}

void deleteIntermediateNode()
{
    struct node *ptr;

    ptr = searchNode();

    if(ptr == NULL)
    {
        printf("Invalid Search. List is Empty");
    }
    else if(ptr->prev == NULL || ptr->next == NULL){
        printf("Invalid Deletion");
    }
    else {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;

        free(ptr);
    }
}

int main()
{

    return 0;
}
