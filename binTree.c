// Write a program to create a Binary search tree (BST) and perform inorder, preorder , and post order traversals

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node {
   int data;
   struct node *left;
   struct node *right;
};

struct node *root = NULL;
struct node *createNode(int data) {
   struct node *newNode= (struct node *)malloc(sizeof(struct node));
   newNode->data=data;
   newNode->left=NULL;
   newNode->right=NULL;
   return newNode;
}
struct node *insertNode(struct node *root,int data) {
   if(root==NULL)
	return createNode(data);
   if(data<root->data) {
	printf("Inserted at left: %d\n",data);
	root->left=insertNode(root->left,data);
   }
   else if(data>root->data) {
	printf("Inserted at right: %d\n",data);
	root->right = insertNode(root->right,data);
   }
   return root;
}

void pre_order_traversal(struct node *root){
   if(root!=NULL) {
	printf("%d ",root->data);
	pre_order_traversal(root->left);
	pre_order_traversal(root->right);
   }
}

void inorder_traversal(struct node *root){
   if(root!=NULL) {
	inorder_traversal(root->left);
	printf("%d ",root->data);
	inorder_traversal(root->right);
   }
}

void post_order_traversal(struct node *root){
   if(root!=NULL) {
	post_order_traversal(root->left);
	post_order_traversal(root->right);
	printf("%d ",root->data);
   }
}


int main() {
   int i,array[7] = {2,5,1,3,9,0,6};
   for(i =0;i<7;i++) {
	root = insertNode(root,array[i]);
   }
   printf("\n Pre_order traversal: ");
   pre_order_traversal(root);
   printf("\n inorder traversal: ");
   inorder_traversal(root);
   printf("\n post_order traversal: ");
   post_order_traversal(root);
   free(root);
   return 0;
}

  