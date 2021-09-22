#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};

struct node *last = NULL;

struct node *createNode()
{
    struct node *n;

    n = (struct node *)malloc(sizeof(struct node));

    return n;
};

//insert at empty list
void insertAtEmpty()
{
    struct node *temp;

    if(last == NULL)
    {
        temp = createNode();

        printf("Enter any value:");
        scanf("%d", &temp->info);

        last = temp;
        last->link = last;
    }
    else {
        printf("List is not Empty");
    }
}

void insertAtStart()
{
    struct node *temp;

    if(last == NULL)
    {
        printf("List is Empty");
    }
    else {
        temp = createNode();

        printf("Enter any value:");
        scanf("%d", &temp->info);

        temp->link = last->link;
        last->link = temp;
    }
}

void insertAtEnd()
{
    struct node *temp;

    if(last == NULL)
    {
        printf("List is Empty");
    }
    else {
        temp = createNode();

        printf("Enter any value:");
        scanf("%d", &temp->info);

        temp->link = last->link;
        last->link = temp;

        last = temp;
    }
}

int main()
{

    return 0;
}
