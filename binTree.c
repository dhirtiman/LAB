// 22. Write a program to create a Binary Search Tree (BST) and perform inorder, preorder, and
// postorder traversals.

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;
struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node *insertNode(struct node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    if (data < root->data)
    {
        printf("inserted at left:\n");
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data)
    {
        printf("inserted at right:\n");
        root->right = insertNode(root->right, data);
    }
    return root;
}
void pre_order_traversal(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        pre_order_traversal(root->left);
        pre_order_traversal(root->right);
    }
}
void inorder_traversal(struct node *root)
{
    if (root != NULL)
    {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}
void post_order_traversal(struct node *root)
{
    if (root != NULL)
    {
        post_order_traversal(root->left);
        post_order_traversal(root->right);
        printf("%d ", root->data);
    }
}
int main()
{
    int i;
    int array[7] = {2, 5, 1, 3, 9, 0, 6};
    for (i = 0; i < 7; i++)
    {
        root = insertNode(root, array[i]);
    }
    printf("\n pre_order travrsal:");
    pre_order_traversal(root);
    printf("\n Inorder travrsal:");
    inorder_traversal(root);
    printf("\n postorder travrsal:");
    post_order_traversal(root);
    free(root);
    return 0;
}

/*
.\binTree.exe
inserted at right:
inserted at left:
inserted at right:
inserted at left:
inserted at right:
inserted at right:
inserted at left:
inserted at left:
inserted at right:
inserted at right:
inserted at left:

 pre_order travrsal:2 1 0 5 3 9 6
 Inorder travrsal:0 1 2 3 5 6 9
 postorder travrsal:0 1 3 6 9 5 2

*/