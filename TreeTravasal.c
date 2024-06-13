#include <stdio.h>
#include <stdlib.h>
 
 //create a node structure

struct Node {
  int data;
  struct Node *left, *right;
};
 

 //create a node
 
struct Node* newNode(int data) {
  struct Node* node = (struct Node*)malloc(sizeof(struct Node));
  node->data = data;
  node->left = node->right = NULL;
  return node;
}
 
void inorderTraversal(struct Node* root) {
  if (root != NULL) {//base condition for recursion
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);//recursive
  }
}
 
void preorderTraversal(struct Node* root) {
  if (root != NULL) {
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
  }
}
 
void postorderTraversal(struct Node* root) {
  if (root != NULL) {
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
  }
}
 
int main() {
 
  struct Node* root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
 
  printf("Inorder traversal: ");
  inorderTraversal(root);
  printf("\n");
 
  
  printf("Preorder traversal: ");
  preorderTraversal(root);
  printf("\n");
 
  
  
  printf("Postorder traversal: ");
  postorderTraversal(root);
  printf("\n");
 
  return 0;
}