// binary tree creation and insert and deleting node
// 21. Write a program to create a binary tree, perform insertion and deletion operations, and
// display the tree after each operation.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *createNode(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert in BST
struct node *insert(struct node *root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Find minimum value node
struct node *findMin(struct node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Delete from BST
struct node *deleteNode(struct node *root, int value)
{
    if (root == NULL)
        return root;

    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else
    {
        // Node with one or no child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children
        struct node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Inorder traversal (Display)
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{
    struct node *root = NULL;
    int choice, value;

    while (1)
    {
        printf("\n--- Binary Search Tree ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display (Inorder)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            printf("Tree after insertion: ");
            inorder(root);
            printf("\n");
            break;

        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            root = deleteNode(root, value);
            printf("Tree after deletion: ");
            inorder(root);
            printf("\n");
            break;

        case 3:
            printf("Tree elements (Inorder): ");
            inorder(root);
            printf("\n");
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }
}

/*
--- Binary Search Tree ---
1. Insert
2. Delete
3. Display (Inorder)
4. Exit
Enter your choice: 1
Enter value to insert: 10
Tree after insertion: 10

--- Binary Search Tree ---
1. Insert
2. Delete
3. Display (Inorder)
4. Exit
Enter your choice: 1
Enter value to insert: 20
Tree after insertion: 10 20

--- Binary Search Tree ---
1. Insert
2. Delete
3. Display (Inorder)
4. Exit
Enter your choice: 1
Enter value to insert: 5
Tree after insertion: 5 10 20

--- Binary Search Tree ---
1. Insert
2. Delete
3. Display (Inorder)
4. Exit
Enter your choice: 1
Enter value to insert: 7
Tree after insertion: 5 7 10 20

--- Binary Search Tree ---
1. Insert
2. Delete
3. Display (Inorder)
4. Exit
Enter your choice: 2
Enter value to delete: 20
Tree after deletion: 5 7 10

--- Binary Search Tree ---
1. Insert
2. Delete
3. Display (Inorder)
4. Exit
Enter your choice: 3
Tree elements (Inorder): 5 7 10

--- Binary Search Tree ---
1. Insert
2. Delete
3. Display (Inorder)
4. Exit
Enter your choice: 4

*/