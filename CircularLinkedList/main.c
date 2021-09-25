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

void viewList()
{
    struct node *t;

    if(last == NULL)
    {
        printf("List is Empty");
    }
    else {
        t = last->link;

        do {
            printf("%d  ", t->info);
            t = t->link;
        }while(t != last->link);
    }
}

void deleteNode()
{
    struct node *t, *ptr;
    int search;

    if(last == NULL)
    {
        printf("List is Empty");
        return;
    }
    printf("Enter any value to be search:");
    scanf("%d", &search);

    //if only one node exist in a list
    if(last == last->link && last->info == search)
    {
        t = last;
        last = NULL;
        free(t);
        return;
    }
    //if only two nodes exist in a list
    if(last->link->info == search)
    {
        t = last->link;
        last->link = t->link;
        free(t);
        return;
    }

    //if we have more than two nodes in a list
    ptr = last->link;

    while(ptr->link != last)
    {
        if(ptr->link->info == search)
        {
            t = ptr->link;
            ptr->link = t->link;
            free(t);
            return;
        }

        ptr = ptr->link;
    }

    //if we have more than two nodes in a list but we want to delete last node of a list
    if(last->info == search)
    {
        t = last;
        ptr->link = last->link;
        last = ptr;
        free(t);
        return;
    }

    printf("Search is not found");
    return;

}

int main()
{
    int choice;

    while(1) // infinite loop
    {
        printf("\npress 1. Insert At Empty\n");
        printf("\npress 2. Insert At Start\n");
        printf("\npress 3. Insert At End\n");
        printf("\npress 4. Delete\n");
        printf("\npress 5. View\n");
        printf("\npress 6. Exit\n");

        printf("\n\nEnter your choice:");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            insertAtEmpty();
            break;

        case 2:
            insertAtStart();
            break;

        case 3:
            insertAtEnd();
            break;

        case 4:
            deleteNode();
            break;

        case 5:
            viewList();
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid Choice");

        }
    }


    return 0;
}
