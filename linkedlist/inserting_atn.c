#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;

};

struct node* head=NULL;

void Print(){
    struct node* temp=head;
    while(temp !=NULL){
    printf("%d",temp->data);
    temp=temp->link;
    }
    printf("\n");
}
int Insert(int value, int n){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=value;
    temp->link=NULL;
    if(n==1){
        temp->link=head;
        head=temp;
        return ;

    }
    struct node* temp2=head;
    for(int i=1;i<n-1;i++){
        temp2=(*temp2).link;
    }
    temp->link=temp2->link;
    temp2->link=temp;


}

void main(){
    Insert(2,1);//2
    Insert(3,2);//23
    Insert(9,2);//2 9 3
    Insert(11,2);//2 11 9 3
    Insert(0,1);//0 2 11 9 3
    Print();
}
