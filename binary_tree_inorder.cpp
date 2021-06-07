#include <stdio.h>
#include <stdlib.h>

struct node {
	int key;
	struct node *left,*right;
};

// a utility function to create a new BST node
struct node *newNode(int item){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

// a utilitty function to do inorder tranversal of BST

void inorder(struct node *root){
	if(root != NULL){
		inorder(root->left);
		printf("\n %d", root->key);
		inorder(root->right);
	}
}

struct node* insert (struct node* node, int key){
	if(node == NULL) return newNode(key);//ih the tree is emty, return a new node
	if(key<node->key)
	node->left = insert(node->left, key);
	else if (key > node->key)
	node->right = insert(node->right, key);
	return node;
}
 int main(){
 	struct node *root = NULL;
 	root = insert(root,50);
 	insert(root,30);
 	insert(root,20);
 	insert(root,40);
 	insert(root,70);
 	insert(root,60);
 	insert(root,80);
 	
 	inorder(root);
 	return 0;
 	
 }
