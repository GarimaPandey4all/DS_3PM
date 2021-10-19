#include <stdio.h>
#include <stdlib.h>

struct node {

    int info;
    struct node *left;
    struct node *right;
};

struct node *createNode(int value)
{
    struct node *n;

    n = (struct node *)malloc(sizeof(struct node));

    n->info = value;
    n->left = NULL;
    n->right = NULL;

    return n;
};

struct node *insertLeft(struct node *root, int value)
{
    root->left = createNode(value);
    return root->left;
};


struct node *insertRight(struct node *root, int value)
{
    root->right = createNode(value);
    return root->right;
};

void preOrder(struct node *root)
{
    if(root != NULL)
    {
        printf("%d  ", root->info);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(struct node *root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        printf("%d  ", root->info);
        inOrder(root->right);
    }
}

void postOrder(struct node *root)
{
    if(root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d  ", root->info);
    }
}

int main()
{
    struct node *root = createNode(1);
    insertLeft(root, 12);
    insertRight(root, 9);
    insertLeft(root->left, 3);
    insertRight(root->left, 5);
    insertLeft(root->right, 4);
    insertRight(root->right, 6);

    printf("PreOrder Traversal:\n");
    preOrder(root);


    printf("\nInOrder Traversal:\n");
    inOrder(root);


    printf("\nPostOrder Traversal:\n");
    postOrder(root);

    return 0;
}
