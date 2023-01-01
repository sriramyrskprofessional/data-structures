#include<stdio.h>

struct node{
    int data;
    struct node* next;
};

struct node* head=NULL;
void Rev(){
    struct node* current=head;
    struct node* prev=NULL;
    struct node* next;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;



}

void Insert(int n){
    struct node* newn=(struct node*)malloc(sizeof(struct node));
    struct node* temp=head;
    if(temp==NULL){
        newn->data=n;
        newn->next=NULL;
        head=newn;
        return;
    }
    newn->data=n;
    newn->next=NULL;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newn;


}
void Print(){
    struct node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void main(){
    Insert(2);
    Insert(3);
    Insert(7);
    Insert(11);
    Insert(20);
    Print();
    Rev();
    Print();

}
