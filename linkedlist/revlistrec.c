#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};

struct node* Revlist(struct node* head){
    struct node* temp=head;

    if(temp->next==NULL){
        head=temp;
        return head;

    }
    head=Revlist(temp->next);

    struct node* next=temp->next;
    next->next=temp;
    temp->next=NULL;
    return head;

}

void Print(struct node* head){
    struct node* temp=head;
    printf("Iterative print\n");
    while(temp!=NULL){

        printf("%d ",temp->data);
        temp=temp->next;

    }
    printf("\n");
}
struct node* Insert(struct node* head,int n,int p){
    int i;
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    struct node* current=head;
    temp->data=n;
    temp->next=NULL;
    if(p==1){
        temp->next=current;
        head=temp;
        return head;

    }
    else{
        for(i=1;i<p-1;i++){
        current=current->next;
        }
        temp->next=current->next;
        current->next=temp;
        return head;
    }

}

void main(){
    struct node* head=NULL;
    head=Insert(head,5,1);
    head=Insert(head,7,2);
    head=Insert(head,9,3);
    head=Insert(head,13,2);
    Print(head);
    head=Revlist(head);
    Print(head);

}
