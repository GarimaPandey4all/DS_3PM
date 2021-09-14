#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};

struct node *start = NULL;

struct node *createNode()
{
    struct node *n;

    n = (struct node *)malloc(sizeof(struct node));

    return n;
};

void insertNode()
{
    struct node *temp, *t;

    temp = createNode();

    printf("Enter any value:");
    scanf("%d", &temp->info);

    temp->link = NULL;

    if(start == NULL) // list is empty
    {
        start = temp;
    }
    else { // list is not empty

        t = start;

        while(t->link != NULL)
        {
            t = t->link;
        }

        t->link = temp;
    }
}

void deleteNode()
{
    struct node *t;

    if(start == NULL)
    {
        printf("List is Empty");
    }
    else {
        t = start;

        start = start->link;

        free(t); // delete first node
    }
}

void searchList()
{
    struct node *t;
    int search;

    if(start != NULL)
    {
        t = start;

        printf("Enter any value to be search:");
        scanf("%d", &search);

        while(t != NULL)
        {
            if(t->info == search)
            {
                printf("%d search value is found.", search);
            }
            t = t->link;
        }
    }
    else
    {
        printf("List is Empty. Invalid Search");
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
            printf("%d  ", t->info);
            t = t->link;
        }
    }
}


int main()
{
    int choice;

    while(1) // infinite loop
    {
        printf("\npress 1. Insert\n");
        printf("\npress 2. Delete\n");
        printf("\npress 3. Search\n");
        printf("\npress 4. View\n");
        printf("\npress 5. Exit\n");

        printf("\n\nEnter your choice:");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            insertNode();
            break;

        case 2:
            deleteNode();
            break;

        case 3:
            searchList();
            break;

        case 4:
            viewList();
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid Choice");

        }
    }

    return 0;
}
