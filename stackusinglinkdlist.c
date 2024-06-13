#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node* next;
};
struct Node* top = NULL;
void push(int value) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = value;
newNode->next = top;
top = newNode;
}
void pop() {
if (top != NULL) {
struct Node* temp = top;
top = top->next;
free(temp);
}
}
void display() {
struct Node* temp = top;
printf("Stack: ");
while (temp != NULL) {
printf("%d ", temp->data);
temp = temp->next;
}
printf("\n");
}
int main() {
push(34);
push(56);
push(78);
display();
pop();
display();
return 0;
}
