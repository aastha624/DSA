#include<stdio.h>
#include<stdlib.h>

//create node structure
struct Node {
int data;
struct Node* left;
struct Node* right;
};

//create a node 
struct Node* createNode(int value) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = value;
newNode->left = newNode->right = NULL;
return newNode;
}
//insert the root data
struct Node* insert(struct Node* root, int value) {
if (root == NULL) {
return createNode(value);
}
if (value < root->data) {
root->left = insert(root->left, value);
} else if (value > root->data) {
root->right = insert(root->right, value);
}
return root;
}

// traversal in order
void inorderTraversal(struct Node* root) {
if (root == NULL) {
return;
}
inorderTraversal(root->left);
printf("%d ", root->data);
inorderTraversal(root->right);
}


// main function
int main() {
struct Node* root = NULL;
root = insert(root, 2);
insert(root, 3);
insert(root, 5);
insert(root, 12);
insert(root, 4);
insert(root, 9);
insert(root, 1);

printf("In-order Traversal: ");
inorderTraversal(root);
printf("\n");
return 0;
}