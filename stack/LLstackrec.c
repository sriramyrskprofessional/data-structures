#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node* next;
};
struct node* head=NULL;
struct node* top=NULL;
//insertion at last
void Insert(int x){
struct node* newn=(struct node*)malloc(sizeof(struct node));
newn->data=x;
newn->next=NULL;
if(head==NULL){
head=newn;
//top=newn;
return;
}
struct node* temp=head;
while(temp->next!=0){
temp=temp->next;
}
temp->next=newn;
//top=newn;
}

//pushing in stack
void push(struct node* ptr){
top=ptr;

}


void pop(){
if(head==top){
top=NULL;
return;
}


struct node* last=head;
last=last->next;
struct node* prvlast=head;
while(last!=top){
last=last->next;
prvlast=prvlast->next;
}
top=prvlast;

}


void del(){
if(head==NULL){
printf("No elements to pop");
return;
}
if(head->next==NULL){
top=NULL;
struct node* temp=head;
free(temp);
head=NULL;
return;
}
struct node* last=head;
last=last->next;
struct node* prvlast=head;
while(last->next!=NULL){
last=last->next;
prvlast=prvlast->next;
}
top=prvlast;
prvlast->next=NULL;
free(last);
return;
}

void reverse(){
struct node* temp=head;
while(temp!=NULL){
push(temp);
temp=temp->next;
}
temp=top;
struct node* temhead=temp;
pop();
while(top!=NULL){
temp->next=top;
pop();
temp=temp->next;
}
temp->next=NULL;
head=temhead;

}

void print(){
struct node* temp=head;

while(temp!=NULL){
printf("%d ",temp->data);
temp=temp->next;
}
}

void main(){

Insert(5);
Insert(6);
Insert(7);
//push(head);
//push(head->next);
//pop();
//pop();
//printf("sriram");
reverse();

print();
}
