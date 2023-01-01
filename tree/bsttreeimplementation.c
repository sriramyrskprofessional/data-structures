#include<stdio.h>
#include<stdlib.h>




struct bstnode{
    int data;
    struct bstnode* left;
    struct bstnode* right;
};
//implementation of queue
struct bstnode* queue[20];
int front=-1;
int rear=-1;

//
void enqueue(struct bstnode* x){
if(front && rear==-1){
front=rear=0;
queue[rear]=x;
//printf("%d %d",front,rear);
return;
}
rear=rear+1;
queue[rear]=x;
return;
}

void dequeue(){
if(front==rear){
front=rear=-1;
}
front=front+1;

}

//max function
int max(int a,int b){
if(a>=b){
return a;
}
else{
return b;
}
}

//creation of a new node in heap
struct bstnode* GetNode(int x){
    //This creates a new node in heap with the size of the bst structure specified the address returened is then typecasted
    struct bstnode* address=(struct bstnode*)malloc(sizeof(struct bstnode));
    address->left=NULL;
    address->right=NULL;
    address->data=x;
    return address;
}
//insert function
struct bstnode* Insert(struct bstnode* root,int x){
        //if root is null then we create a new node with left and right ptrs as null
        if(root==NULL){
            root=GetNode(x);
        }
        //if the insertion value is lless than or equal to root value then
        else if(x <=root->data){
            root->left=Insert(root->left,x);
        }
        else{
            root->right=Insert(root->right,x);
        }
        return root;
}
//search function
int bst_search(struct bstnode* root,int x){
   int key=1;
    if(root==NULL){
        return 0;
    }
    else if(root->data==x){
        return 1;
    }
    else if(x<=root->data){
        return bst_search(root->left,x);
    }
    else{
       return bst_search(root->right,x);
    }


}
//finding the height of the tree
int t_height(struct bstnode* root){
    if(root==NULL){
        return -1;
    }
    int right,left;
    right=t_height(root->right);
    left=t_height(root->left);

    return max(right,left)+1;
}
//depth  level traversing(breadth first)
void lvltraverse(struct bstnode* root){
printf("\nLevel order traversal :  ");
enqueue(root);

while(front != -1&& rear != -1){
if(queue[front]==NULL){
dequeue();

}
else{
printf(" %d ",queue[front]->data);
enqueue(queue[front]->left);
enqueue(queue[front]->right);
dequeue();
}


}

}
//depth first traversing
//postorder
void postorder(struct bstnode* root){
if(root==NULL) return;
postorder(root->left);
postorder(root->right);
printf(" %d ",root->data);
}

//preorder
void preorder( struct bstnode* root){
if(root==NULL)return;
printf(" %d ",root->data);
preorder(root->left);
preorder(root->right);
}
//inorder
void inorder(struct bstnode* root){
if(root==NULL) return;
inorder(root->left);
printf(" %d ",root->data);
inorder(root->right);
}

void main(){
    int key=1;
    struct bstnode* root=NULL;
    root=Insert(root,15);
    root=Insert(root,25);
    root=Insert(root,5);
    root=Insert(root,10);
    root=Insert(root,112);
    root=Insert(root,113);
    key=bst_search(root,112);

    if(key==1){
        printf("The element is found ");

    }
    else{
        printf("Element not found");
    }
    int height;
    height=t_height(root);
    printf("\n%d - height",height);
    lvltraverse(root);
    printf("\npreorder : ");
    preorder(root);
    printf("\ninorder : ");
    inorder(root);
    printf("\npostorder : ");
    postorder(root);

}
