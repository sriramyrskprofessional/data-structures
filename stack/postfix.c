#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//creating a structrue for my stack
struct stack{
int array[30];
int top;
};
//Pushing the elements into a stack
void push(struct stack* obj,int x){
//incrementing the top ptr and pushing x into array[top]
obj->top=obj->top+1;
obj->array[obj->top]=x;
return;
}
//Poping the elements from stack
void pop(struct stack* obj){
obj->top=obj->top-1;

}
//Evalutation of post fix
int postfix(int a1,int a2,char a3){
//checking the type of oprator string and doing that specific operations
if(a3 == '+'){

return a1+a2;
}
else if(a3 == '-'){
return a1-a2;
}
else if(a3 == '*'){
return a1*a2;
}
else if(a3 == '/'){
return a1/a2;
}
}


void main(){
char string[30];
int length,i,ans;
struct stack* s1=(struct stack*)malloc(sizeof(struct stack));
s1->top=-1;
printf("Enter an infix expression : ");
scanf("%[^\n]%*c",string);
length=strlen(string);
for(i=0;i<length;i++){

if(string[i]>='0' && string[i]<='9'){
//setting operand as 0
//checking if the char is a number
//for a number with more than 1 digit we multiply existing oprand by 10 and add the value
int operand;
operand=0;
while(i<length && string[i]>='0' && string[i]<='9'){
operand = (operand*10)+(string[i]-'0');
i++;
printf("\n%d \n",operand);
}
//the loop would have exited because string[i] is not a number so we will have to decrement i for checking other condtions
i--;

push(s1,operand);
}
else if(string[i]=='+'||string[i]=='-'||string[i]=='*'||string[i]=='/'){
int op1,op2,res;
//taking the last 2 operands in case we find and operator as string[i]
//performing the operation and pushing it back intoo stack again
op2=s1->array[s1->top];pop(s1);
op1=s1->array[s1->top];pop(s1);
printf("\n%d %d %d\n",op2,op1,i);
res=postfix(op1,op2,string[i]);
push(s1,res);
}
else if(string[i]==' '){
continue;
}
}
ans=s1->array[s1->top];
printf("The answer is %d",ans);
}


