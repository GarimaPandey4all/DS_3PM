#include <stdio.h>
#include <stdlib.h>

struct node {

    struct node *prev;
    int info;
    struct node *next;
};

struct node *start = NULL;

struct node *searchNode()
{
    struct node *temp;
    int search;

    if(start == NULL)
    {
        return NULL;
    }
    else {
        printf("Enter any value to be search:");
        scanf("%d", &search);

        temp = start;

        while(temp != NULL)
        {
            if(temp->info == search)
            {
                return temp;
            }
            temp = temp->next;
        }

        return NULL;
    }
};

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
            printf("%d  ", t->info);
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
    int choice;

    while(1) // infinite loop
    {
        printf("\npress 1. InsertAtFirst\n");
        printf("\npress 2. InsertAtLast\n");
        printf("\npress 3. Insert After Node\n");
        printf("\npress 4. Delete First Node\n");
        printf("\npress 5. Delete Last Node\n");
        printf("\npress 6. Delete Intermediate Node\n");
        printf("\npress 7. View List\n");
        printf("\npress 8. Exit\n");

        printf("\n\nEnter your choice:");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            insertAtStart();
            break;

        case 2:
            insertAtLast();
            break;

        case 3:
            insertAfterNode();
            break;

        case 4:
            deleteFirstNode();
            break;

        case 5:
            deleteLastNode();
            break;

        case 6:
            deleteIntermediateNode();
            break;

        case 7:
            viewList();
            break;

        case 8:
            exit(0);

        default:
            printf("Invalid Choice");

        }
    }

    return 0;
}
