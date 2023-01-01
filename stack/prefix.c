#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//creating a stack
struct stack{
int array[30];
int top;
};
//pushing element into stack
void push(struct stack* obj, int x){
obj->top=obj->top+1;
obj->array[obj->top]=x;
return;
}
//poping elements from the stack
void pop(struct stack* obj){
obj->top=obj->top-1;
return;
}
//evalutating prefix exp
int prefixeval(int a, int b, char c){
if(c == '+') return a+b;
if(c == '-') return a-b;
if(c == '*') return a*b;
if(c == '/') return a/b;
}
void main()
{
char string[30];
int i,length;
struct stack* s1=(struct stack*)malloc(sizeof(struct stack));
s1->top=-1;
printf("Enter a prefix expression : ");
scanf("%[^\n]%*c",string);
length=strlen(string);
i=length-1;
//reading the expression in reverse order
for(i;i>=0;i--){
if(string[i]==' '){
//carry on if the char is empty space
continue;
}
else if(string[i]=='+' || string[i]=='-' || string[i]=='*' || string[i]=='/' )
{
//if operand the perform operation with top 2 elements of the stack
//And push the result into the stack back again
int operand1,operand2,result;
operand1=s1->array[s1->top];
pop(s1);
operand2=s1->array[s1->top];
pop(s1);
result=prefixeval(operand1,operand2,string[i]);
//printf("\n %d %d %d",operand1, operand2, result);
push(s1,result);
}
else if( string[i]>='0' && string[i]<='9'){
//If the string is a number then  for every digit that we will multiply the number with its position value
/*Eg: if 210
opr=o*1=0
opr=1*10=10
opr=2*200=200+10=210
*/
int opr=0,count=1;
while(string[i]>=0 && string[i]>='0' && string[i]<='9'){

opr=((string[i]-'0')*count)+opr;
count=count*10;


i--;
}
//we push the final answer into stack
//We exit the loop because the char is not a number so it could be an operator
//Hence to check the oprator condtiton block we are now again going 1 step back by incrementing i since its is right to left process

i++;
push(s1,opr);
}
}
printf("The answer is %d ",s1->array[s1->top]);
}
