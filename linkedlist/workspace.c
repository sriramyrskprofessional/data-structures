#include<stdio.h>
#include<stdlib.h>

struct node{
char ch;
struct node *next;
};
struct node *head=NULL;

struct node *p1=NULL;
void addnode(char ch) {
if(head==NULL) {
    struct node *New=(struct node *) malloc (sizeof(struct node));
    head=New;
    New->ch=ch;
    New->next=NULL;
}

else {
    struct node *New=(struct node *) malloc (sizeof(struct node));
    New->ch=ch;
    New->next=NULL;
    for(p1=head;p1->next!=NULL;p1=p1->next);
        p1->next=New;
}
}

void main() {
char ch,frm,to;
printf("\nEnter the string");
while((ch=getchar())!='\n')
    addnode(ch);
for(p1=head;p1!=NULL;p1=p1->next)
    printf("\n%c",p1->ch);
}
