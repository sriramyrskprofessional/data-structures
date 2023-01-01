#include<stdio.h>

struct node{
    int data;
    struct node* next;

};

struct node* head=NULL;

void Insert(int value, int x){
    int i;
    struct node* temp1=(struct node*)malloc(sizeof(struct node));
    temp1->data=value;
    temp1->next=NULL;
    if(x==1){
        temp1->next=head;
        head=temp1;
        return;
    }
    struct node* temp2=head;
    for(i=1;i<x-1;i++){
        temp2=temp2->next;
    }
    temp1->next=temp2->next;
    temp2->next=temp1;

}

void Print(){
    struct node* temp1=head;
    while(temp1 != NULL){
        printf("%d",temp1->data);
        temp1=temp1->next;

    }
    printf("\n");
}

void Delete(n){
    int i;
    struct node* nbefore=head;

    if(n==1){
        struct node* temp=head;
        head=temp->next;
        free(temp);

    }

    for(i=1;i<n-1;i++){
        nbefore=nbefore->next;

    }
    struct node* nth=nbefore->next;
    nbefore->next=nth->next;
    free(nth);


}
void main(){
int n;
    Insert(7,1);
    Insert(2,2);
    Insert(5,3);
    Insert(6,1);
    Print();
    printf("Enter a postion to be deleted : ");
    scanf("%d",&n);
    Delete(n);
    Print();
}
