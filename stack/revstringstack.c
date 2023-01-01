#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max 20

struct stack{
int top;
int array[20];
};

//
void push(char x , struct stack* obj){
if(obj->top>=Max-1){
printf("stack is full");return;
}
obj->top=obj->top+1;
obj->array[obj->top]=x;

return;
}

//
void pop(struct stack* obj){
if(obj->top<0){
printf("stack is empty"); return;
}
obj->top=obj->top-1;
}

//
void main(){
struct stack* obj=(struct stack*)malloc(sizeof(struct stack));
obj->top=-1;
char c[15];

printf("Enter a string to be reversed : ");
 scanf("%s", c);

int length=strlen(c);
for(int i=0;i<length;i++){
    push(c[i],obj);
}
for(int i=0;i<length;i++){
    push(c[i],obj);
}
for(int i=0;i<length;i++){
    c[i]=obj->array[obj->top];

    pop(obj);
}
printf("The reversed string is %s ",c);
}


