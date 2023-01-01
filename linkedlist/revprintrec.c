#include<stdio.h>

struct node{
    int data;
    struct node* next;
};

void RevPrint(struct node* p){
    if(p==NULL){
    printf("\n");
    return;
    }

    RevPrint(p->next);

    printf("%d ",p->data);


}

void Print(struct node* head){
    if(head==NULL) {printf("\n"); return;}
    printf("%d ",head->data);
    Print(head->next);

}


struct node* Insert(struct node* head,int value){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=value;
    temp->next=NULL;
    struct node* temp1=head;
    if(head==NULL){
        head=temp;
    }
    else{
        while(temp1->next!=NULL){
            temp1=temp1->next;
        }
        temp1->next=temp;
    }
    return head;
}

void main(){
    struct node* head=NULL;
    head=Insert(head,3);
    head=Insert(head,4);
    head=Insert(head,6);
    head=Insert(head,7);
    head=Insert(head,9);
    head=Insert(head,31);
    Print(head);
    RevPrint(head);
}
