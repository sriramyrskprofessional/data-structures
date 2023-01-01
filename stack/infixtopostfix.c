#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char result[30]=" ";
char stack[30];
int top=-1;
//creation of the push function
void push(char x){
//incrementing top and pushing elements into the stack
top=top+1;
stack[top]=x;
return;
}
//creation of pop function
void pop(){
//Decrementing pop
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
//Checking the precidence of symbol
int priority_check(char x){
//If the symbol is + or - then priority is 1
if(x=='+' || x== '-'){
return 1;
}
//If the symbol is * or / then priority must be more than 1
else if(x=='*' || x =='/'){
return 2;
}
}
//Check if the precedence of top is higher than reading char
int high_opr_precd(char x){
//if priority of top is greater than priority of reading char then return true
if(priority_check(stack[top])>=priority_check(x)){
return 1;
}
else{
return 0;
}

}
//Check if it is an opening
int OpenParanthesis(char x){
if(x == '('|| x== '['|| x=='{'){
return 1;
}
else{return 0;}
}
//Check if it is a closing
int CloseParanthesis(char x){
if(x==')' || x==']' || x=='}'){
return 1;
}
else return 0;
}
//
//Function that converst the expression
void infix_to_postfix(char string[30]){
int i;
int length=strlen(string);

for(i=0;i<length;i++){
//if the char is operand then add to result
if(isOperand(string[i])==1){
strncat(result,&string[i],1);
}
else if(isOperator(string[i])==1){
//if the char is opertator then check for precedence if the precedence of stack is greater than char then pop all symbols nad add to result
while(top>=0 && high_opr_precd(string[i]) == 1 && OpenParanthesis(stack[top])!=1 ){
strncat(result, &stack[top], 1);
pop();
}
//if precedence is not high then add char to stack
push(string[i]);

}
else if(OpenParanthesis(string[i])==1){
//if open bracket encountered then push it into stack
push(string[i]);
}
else if(CloseParanthesis(string[i])==1){
//if close bracket is encountered then pop elements and add it into result untill a open bracket is found
while(top>=0 && OpenParanthesis(stack[top])!=1 ){
strncat(result, &stack[top], 1);

pop();
}
//then pop the current top which  is the open bracket itself
pop();
}

}
//After checking all chars if operands remain in stack then pop all of them and add it to the result
while(top>=0){
strncat(result, &stack[top], 1);
pop();
}
//print the result
printf("%s",result);
}


void main(){
//Getting the user input
char string[30];
printf("Enter an infix expression to be converted : ");
scanf("%[^\n]%*c",string);
infix_to_postfix(string);
}
