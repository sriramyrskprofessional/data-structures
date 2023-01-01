#include<stdio.h>
#include<stdlib.h>
//creating the node structure
struct node{
    int data;
    struct node* next;
};
//creating the head var
struct node* head=NULL;
//Insert functions
//Insert at begning
void Insert_beg(){
    int e;
    printf("Enter the element to be inserted : ");
    scanf("%d",&e);
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=e;
    newnode->next=head;
    head=newnode;

}
//Insert at postion
void Insert_pos(){
    int e,p,i;
    struct node* nminus=head;
    printf("Enter the element to be inserted : ");
    scanf("%d",&e);
    printf("Enter the postion: ");
    scanf("%d",&p);
    //creating the node
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=e;
    newnode->next=NULL;
    //at 1st
    if(p==1){
        newnode->next=head;
        head=newnode;
        return;
    }
    //at anypostion
    for(i=1;i<p-1;i++){
        nminus=nminus->next;

    }
    newnode->next=nminus->next;
    nminus->next=newnode;
    return;
}
//Insert at end
void Insert_end(){
    int e;
    struct node* end=head;
    printf("Enter the element to be inserted : ");
    scanf("%d",&e);
    //creating a node
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=e;
    newnode->next=NULL;
    if(end==NULL){
        head=newnode;
        return;
    }
    //traversing for last node
    while(end->next!=NULL){
        end=end->next;
    }
    end->next=newnode;


}

//Delete
//Delete by position
void Delete(int p){
    int i;
    struct node* pnode=head;

    //if first is to be deleted
    if(p==1){
        head=pnode->next;
        free(pnode);
        return;

    }
    //traversing to the previous of the node to be deleted
    for(i=1;i<p-1;i++){
        pnode=pnode->next;
    }
    //going to the node to be deleted
    struct node* dnode=pnode->next;
    //changing links
    pnode->next=dnode->next;
    free(dnode);




}
//Delete by value
void Delete_val(){
    int v,i;
    struct node* current=head;
    printf("Enter the value to be deleted : ");
    scanf("%d",&v);
    i=1;
    while(current!=NULL){

    //checking if the data at each node is matching with our delete value
        if(current->data==v){
            Delete(i);
            return;
        }
        else{
            current=current->next;
            i++;
        }

    }



}
//Print
//Print by iteration
void Print(){
    struct node* current=head;
    printf("\nTHE LIST IS : \n");
    //traversing to the last node
    while(current!=NULL){
        //printing the values
        printf("%d ",current->data);
        current=current->next;
    }
    printf("\n");

}
//Print by recursion
void Rec_print(struct node* q){

    if(q==NULL){
        return;
    }
    printf("%d ",q->data);//print the head value at the node
    Rec_print(q->next);//making it print by recursively calling the next node


}
//Reverse Print by recursion
void Rev_print(struct node* p){

    //reaching the last node
    if(p==NULL){
        return;
    }
    Rev_print(p->next);//reaching the last node
    printf("%d ",p->data);//returning in reverse order

}
//Reversing the linked list
//By Iteration
void Revli_it(){
    struct node* current=head;
    struct node* next=NULL;
    struct node* previous=NULL;
    while (current!=NULL){
        next=current->next;
        current->next=previous;
        previous=current;
        current=next;
    }
    head=previous;
}
//Reversing using recursion
void Revli_rec(struct node* t){
    //Stoping at the end of the list
    if(t->next==NULL){
        head=t;
        return;
    }
    Revli_rec(t->next);
    //Coming from reverse order
    struct node* nextnode=t->next;
    nextnode->next=t;
    t->next=NULL;



}


void main(){
    int status=1;
    int operation,insert,lldelete,llprint,llreverse,p;
    printf("\t\tThe singly linked list\n");
    printf("Enter the operation you want to perform on the linked list : \n");
    while(status==1){
    printf("\n");
    printf("1.Insert 2.Delete 3.Print 4.Reverse 5.exit : ");
    scanf("%d",&operation);
    switch(operation){
        case 1:
            printf("Insert at 1.beggning 2.postion 3.end : ");
            scanf("%d",&insert);
            switch(insert){
                case 1:
                Insert_beg();
                break;
                case 2:
                Insert_pos();
                break;
                case 3:
                Insert_end();
                break;
                default:
                    printf("Enter a valid choice");
                break;

            }
            break;
        case 2:
            printf("Delete by 1.postion 2.value : ");
            scanf("%d",&lldelete);
            switch(lldelete){
                case 1:
                    printf("Enter the position to be deleted : ");
                    scanf("%d",&p);
                    Delete(p);
                    break;
                case 2:
                    Delete_val();
                    break;
                default:
                    printf("Enter a valid choice");
                    break;
            }
            break;
        case 3:
            printf("1.Print by iteration 2.print by recursion 3.revprint by recursion : ");
            scanf("%d",&llprint);
            switch(llprint){
                case 1:
                    Print();
                    break;
                case 2:
                    printf("\nTHE LIST IS : \n");
                    Rec_print(head);
                    break;
                case 3:
                    printf("\nTHE LIST IS : \n");
                    Rev_print(head);
                    break;
                default:
                    printf("Enter a valid choice");
                    break;
            }
            break;
        case 4:
        printf("1.By iteration 2.by recursion: ");
        scanf("%d",&llreverse);
        switch(llreverse){
            case 1:
                Revli_it();
                break;
            case 2:
                Revli_rec(head);
                break;
            default:
                printf("Enter a valid choice");
                break;

        }
        break;
        case 5:
            status=0;
            break;

        default:
        printf("Enter a valid choice");
        break;


    }


    }


}
