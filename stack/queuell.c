#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node* next;
};

struct node* front=NULL;
struct node* rear=NULL;

//isEMpty
int is_Empty(){
if(front==NULL && rear==NULL) {return 1;}
else {return 0;}
}
//create node
struct node* create_node(int x){
struct node* address=(struct node*)malloc(sizeof(struct node));
address->data=x;
address->next=NULL;
}
//Enqueue
void enqueue(int x){
struct node* newnode=create_node(x);
if(is_Empty()==1){
rear=front=newnode;
return;
}
rear->next=newnode;
rear=newnode;
}
//dequeue
void dequeue(){
struct node* clear=front;
front=front->next;
free(clear);
}
//print
void print(){
struct node* temp=front;
printf("\n");
printf("front->  ");
while(temp!=NULL){
printf("%d ",temp->data);
temp=temp->next;
}
printf("  <-rear");
}
void main(){
enqueue(3);enqueue(19);enqueue(13);enqueue(2);
dequeue();dequeue();dequeue();dequeue();
print();
}
