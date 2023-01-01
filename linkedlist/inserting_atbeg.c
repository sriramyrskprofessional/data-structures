#include<stdio.h>
#include<stdlib.h>

struct node{
    char data;
    struct node* next;
};
int x;
int i;

struct node* head=NULL;
void Insert(char ch);
void Print();


void Insert(char ch){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    (*temp).data=ch;
    (*temp).next=head;
    head=temp;
}
void Print(){
    struct node* temp=head;
    printf("The elements are ");
    while(temp!=NULL){
        printf("%c ",(*temp).data);
        temp=(*temp).next;

    }
    printf("\n");
}
int main(){
    void Insert(char ch);
    void Print();

    char ch;

    printf("Enter the number of charecters : ");
    scanf("%d",&x);
    for(i=0;i<x;i++){
    printf("%d",x);
        printf("\nEnter the element : ");

        scanf("%s",&ch);

        Insert(ch);

        Print();



    }

}



