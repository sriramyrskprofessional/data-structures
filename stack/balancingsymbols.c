#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int top=-1;
char array[30];
void push(char x){
top=top+1;
array[top]=x;
return;
}
void pop(){

top=top-1;
}

void main(){
int i;

char string[30];
printf("Enter the expression : ");
scanf("%s",string);
int str_len=strlen(string);
for(i=0;i<str_len;i++){

if(string[i]=='{'){
    push(string[i]);


}
else if(string[i]=='['){
    push(string[i]);
}
else if(string[i]=='('){
    push(string[i]);

    //printf("%c ",string[i]);
    //printf("%d",top);

}
else if(string[i]=='}'){
    if(array[top]=='{'){
    pop();
    }
    else if(top<0){
    printf("The expression is unbalanced");
    return;
    }
    else{
        printf("The expression is unbalanced");
    }
}
else if(string[i]==']'){
    if(array[top]=='['){
    pop();
    }
    else if(top<0){
    printf("The expression is unbalanced");
    return;
    }
    else{
        printf("The expression is unbalanced");
    }
}
else if(string[i]==')'){
    if(array[top]=='('){
    //printf("%c ",string[i]);
     //printf("%d",top);
    pop();
    }
    else if(top<0){
    printf("The expression is unbalanced");
    return;
    }
    else{
        printf("The expression is unbalanced");

    }
}

}
if(top<0){
printf("The expression is balanced");
}
}

