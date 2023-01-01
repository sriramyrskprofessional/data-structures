#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node* prev;
struct node* next;
};

struct node* head=NULL;

//creating a new node

struct node* create_node(int x){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=x;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}

//writing the insert
//beg
void insert_head(int x){
struct node* newNode=create_node(x);
if(head==NULL){
    head=newNode;
    return ;
}
head->prev=newNode;
newNode->next=head;
head=newNode;

}
//ar tail
void insert_tail(int x){
struct node* newNode=create_node(x);
struct node* lastNode=head;
if(head==NULL){
    head=newNode;
    return;
}
while(lastNode->next!=NULL){
    lastNode=lastNode->next;
}
lastNode->next=newNode;
newNode->prev=lastNode;

}
//print
void print(){
struct node* currentNode=head;
printf("\n");
while(currentNode!=NULL){
    printf("%d ",currentNode->data);
    currentNode=currentNode->next;

}
printf("\n");

}
//rev print
void Revprint(){
struct node* currentNode=head;
printf("\n");
while(currentNode->next!=NULL){
    currentNode=currentNode->next;
}
while(currentNode!=NULL){
    printf("%d ",currentNode->data);
    currentNode=currentNode->prev;
}

}
void main(){
insert_tail(8);
insert_head(2);
insert_head(5);
insert_head(6);

insert_tail(12);
print();
Revprint();
}
