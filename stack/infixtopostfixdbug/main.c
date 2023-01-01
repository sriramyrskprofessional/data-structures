#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char result[30]=" ";
char stack[30];
int top=-1;
//creation of the push function
void push(char x){
top=top+1;
stack[top]=x;
return;
}
//creation of pop function
void pop(){
top=top-1;
return;
}
//operator check
int isOperator(char x){
if(x == '+' ||x == '-' || x == '*' ||x == '/') {
    return 1;
}
else{
    return 0;
}
}
//operaand Check
int isOperand(char x){
if((x>='a' && x<='z')||(x>='A' && x<= 'Z')){
return 1;
}
else{
return 0;
}
}
//
int priority_check(char x){
if(x='+' || '-'){
return 1;
}
else if(x='*' || '/'){
return 2;
}
}
//
int high_opr_precd(char x){
int priority = 0;
if(priority_check(stack[top])>=priority_check(x)){
return 1;
}
else{
return 0;
}

}
//
int OpenParanthesis(char x){
if(x == '('||'['||'{'){
return 1;
}
else{return 0;}
}
//
int CloseParanthesis(char x){
if(x=')' || ']' || '}'){
return 1;
}
else return 0;
}
//
//Function that converst the expression
void infix_to_postfix(char string[30]){

//  char result[30]=" ";
int i;
int length=strlen(string);

for(i=0;i<length;i++){
// printf("\n string[i] == %c",string[i]);
if(isOperand(string[i])==1){
strncat(result,&string[i],1);
// printf("\n string[i] == %c",string[i]);
}
else if(isOperator(string[i])==1){
while(top>=0 && high_opr_precd(string[i]) == 1 && OpenParanthesis(stack[top])!=1 ){
strncat(result, &stack[top], 1);
pop();
}
push(string[i]);

}
else if(1==OpenParanthesis(stack[i])){
push(string[i]);
}
else if(CloseParanthesis(stack[i])==1){
while(top>=0 && OpenParanthesis(stack[top])!=1 ){
strncat(result, &stack[top], 1);

pop();
}
}

}
while(top>=0){
strncat(result, &stack[top], 1);
pop();
}
}


void main(){
//Getting the user input
char string[30];
printf("Enter an infix expression to be converted : ");
scanf("%[^\n]%*c",string);
infix_to_postfix(string);
printf("%s",result);
}
