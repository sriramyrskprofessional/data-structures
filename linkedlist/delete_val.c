#include<stdio.h>

struct node{
    int data;
    struct node* next;

};

struct node* head=NULL;

void Insert(int value, int pos){
    int i;
    struct node* nth=(struct node*)malloc(sizeof(struct node));
    nth->data=value;
    nth->next=NULL;

    if(pos==1){
        nth->next=head;
        head=nth;
        return;

    }

    struct node* nprev=head;

    for(i=1;i<pos-1;i++){
        nprev=nprev->next;

    }
    nth->next=nprev->next;
    nprev->next=nth;

}
void Print(){
    struct node* temp1=head;
    while(temp1!=0){
        printf("%d",temp1->data);
        temp1=temp1->next;
    }
    printf("\n");

}
void Delete_v(int val){
int i=1;
    struct node* temp=head;
    while(temp!=0){
        if(temp->data==val){
            Delete(i);
            return;

        }
        i++;
        temp=temp->next;
    }

}
void Delete(int pos){
int i;
struct node* temp=head;
if(pos==1){
    head=temp->next;
    free(temp);
    return;

}
for(i=1;i<pos-1;i++){
    temp=temp->next;
}
struct node* tempn=temp->next;
temp->next=tempn->next;
free(tempn);


}

void main(){
    Insert(7,1);
    Insert(8,1);
    Insert(9,3);
    Print();
    Delete_v(9);
    Print();
}
