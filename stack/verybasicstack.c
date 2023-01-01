#include<stdio.h>
#define MAX 101
int top=-1;
int a[MAX];
void push(int x){
if(top==MAX-1){
    printf("The stack is over flowing");
    return;
}
a[++top]=x;
return;
}
void pop(){
if(top<0){
printf("The stack is underflowing");
return;
}
--top;
return;
}
void print(){
int i=0;
printf("\n");
for(i;i<=top;i++){
    printf(" %d ",a[i]);
}
return;
}
void main(){

push(5);print();
push(7);print();
push(9);print();
pop();print();
push(3);print();
pop();print();
pop();print();
push(9);print();


}
