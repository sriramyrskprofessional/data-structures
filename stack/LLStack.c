#include<stdio.h>
struct node{
int data;
struct node *link;
};

struct node* top=NULL;
//creating a node
struct node* create_node(int x){
struct node* address=(struct node*)malloc(sizeof(struct node));
address->data=x;
address->link=NULL;
return address;
}
//at the begning of the node
void push(int x){
struct node* node=create_node(x);
node->link=top;
top=node;

}
//delete node t begning
void pop(){
struct node* del=top;
if(top==NULL) return;
top=top->link;
free(del);
}
//isempty
int isempty(){
if(top<1){
return 0;
}
else{
return 1;
}
}
//top
struct node* topl(){
return top;
}
//print
void print(){
struct node *temp=top;
printf("\n");
while(temp !=NULL){
printf("%d ",temp->data);
temp=temp->link;
}
}

void main(){
push(5);print();
push(7);print();
push(9);print();
pop();print();
push(100);print();
pop();print();
pop();print();
printf("\n Empty %d",isempty());
printf("\n Top %d",topl());
}
