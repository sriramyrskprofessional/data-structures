#include<stdio.h>
#include<stdlib.h>

int queue[20];
int front=-1;
int rear=-1;
int N=5;
//To check if the queue is empty
int is_Empty(){
if(front ==-1 && rear ==-1){
return 1;
}
else{
return 0;
}
}
//To check if the queue is full
int is_Full(){
if((rear+1)%N == front){
return 1;
}
else{
return 0;
}
}

//Enqueue
void enqueue(int x){
if(is_Full()==1){
printf("\nThe queue is full !");
return;
}
else if(is_Empty()==1){
front=rear=0;

}
else{
rear=(rear+1)%N;
}
queue[rear]=x;
}
//Dequeue

void dequeue(){
if(is_Empty()==1){
printf("The queue is empty!");
return;
}
else if(front==rear){
front=rear=-1;
}
else{
front=(front+1)%N;
}
}


void main(){

enqueue(12);
enqueue(11);
enqueue(10);
enqueue(19);
enqueue(15);
dequeue();
enqueue(9);

int i=front;
while(i!=rear){
printf("%d ",queue[i]);
i=(i+1)%N;
}
printf("%d ",queue[i]);
}
