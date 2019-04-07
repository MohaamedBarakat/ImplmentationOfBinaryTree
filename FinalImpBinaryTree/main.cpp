#include <iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
typedef int eleType;
typedef struct tnode{
eleType data;
struct tnode *left;
struct tnode *right;
}TNode;
typedef TNode *Btree;
TNode*insertLeft(Btree t,eleType x);
TNode*insertRight(Btree t,eleType x);
TNode*insertBST(Btree t,eleType x);
TNode*FindMin(Btree t);
TNode*finMax(Btree t);
TNode *findBST(Btree t,eleType x);
void preOrder(Btree t);
void inOrder(Btree t);
void postOrder(Btree t);
int height(Btree t);
int Size(Btree t);
int SameTree(Btree t1,Btree t2);
TNode* Swap(Btree t);
int siize(Btree t);
int sum(Btree t);
TNode*CopyTree(Btree t1,Btree t2);
int main()
{
    Btree t1,t2;
    t1=t2=NULL;
    t1=insertLeft(t1,5);
    t1=insertLeft(t1,7);
    t1=insertRight(t1,6);
    t1=insertBST(t1,9);
    t1=insertBST(t1,2);
    t1=insertRight(t1,88);
    cout<<sum(t1)<<endl;
    cout<<endl;
    inOrder(t1);
Swap(t1);
cout<<endl;

    t2=CopyTree(t1,t2);
    inOrder(t2);
   /* t2=insertLeft(t2,5);
    t2=insertLeft(t2,7);
    t2=insertRight(t2,6);
    t2=insertBST(t2,9);
    t2=insertBST(t2,2);
    t2=insertRight(t2,0);
    cout<<SameTree(t1,t2)<<endl;

    t2=findBST(t1,9);
    t2=FindMin(t1);
    t2=finMax(t1);
    cout<<endl;
    inOrder(t1);
    cout<<endl;
    preOrder(t1);
    cout<<endl;
    postOrder(t1);
    cout<<endl;
    int x=height(t1);
    cout<<x<<endl;
    cout<<Size(t1);*/
    return 0;
}
TNode*insertLeft(Btree t,eleType x){
TNode *tmp;
tmp=(TNode*)malloc(sizeof(TNode));
if(tmp==NULL)return NULL;
tmp->data=x;
tmp->left=tmp->right=NULL;
if(t==NULL)
    t=tmp;
else if(t->left==NULL)
    t->left=tmp;
else
    t->left=insertLeft(t->left,x);
return t;

}
TNode*insertRight(Btree t,eleType x){
TNode *tmp;
tmp=(TNode*)malloc(sizeof(TNode));
if(tmp==NULL)return NULL;
tmp->data=x;
tmp->left=tmp->right=NULL;
if(t==NULL)
    t=tmp;
else if(t->right==NULL)
    t->right=tmp;

else t->right=insertRight(t->right,x);
return t;
}
TNode*insertBST(Btree t,eleType x){
TNode *tmp;
tmp=(TNode*)malloc(sizeof(TNode));
if(tmp==NULL)return NULL;
tmp->data=x;
tmp->left=tmp->right=NULL;
if(t==NULL)
    t=tmp;
else if(x<t->data){
    t->left=insertBST(t->left,x);
}
else if(x>t->data)
    t->right=insertBST(t->right,x);
return t;

}
TNode*FindMin(Btree t){
TNode *tmp;
tmp=t;
if(tmp==NULL)return NULL;
if(tmp->left!=NULL)
    return(FindMin(tmp->left));
    return tmp;
}
TNode*finMax(Btree t){
tnode *tmp;
tmp=t;
if(tmp==NULL)return NULL;

if(tmp->right!=NULL)return(finMax(tmp->right));
return tmp;
}
TNode *findBST(Btree t,eleType x){
tnode *tmp;
tmp=t;
if(tmp==NULL)return NULL;
else if(tmp->data==x)return tmp;
else if(x<tmp->data)return(findBST(tmp->left,x));
else if(x>tmp->data)return(findBST(tmp->right,x));
else return NULL;
}
void preOrder(Btree t){
     if(t!=NULL){
cout<<t->data<<" ";
preOrder(t->left);
preOrder(t->right);
     }
}
void inOrder(Btree t){
     if(t!=NULL){
inOrder(t->left);
cout<<t->data<<" ";
inOrder(t->right);
     }

}
void postOrder(Btree t){
    if(t!=NULL){
postOrder(t->left);
postOrder(t->right);
cout<<t->data<<" ";
    }

}
int height(Btree t){
int h,Max;
if(t==NULL)return -1;
h=height(t->left);
Max=height(t->right);
if(h>Max)
    Max=h;
return(Max+1);
}
int count=0;
int Size(Btree t){
    if(t!=NULL){
count++;
Size(t->left);
Size(t->right);}
return count;

}
int siize(Btree t){
if(t==NULL)return 0;
    else{
    return (1+siize(t->left)+siize(t->right));
}
}
int sum(Btree t){
if(t==NULL)return 0;
else return t->data+sum(t->left)+sum(t->right);

}
int SameTree(Btree t1,Btree t2){
if(t1==NULL&&t2==NULL)return 1;

if(t1!=NULL){
    if(t1->data!=t2->data)return 0;
    return SameTree(t1->left,t2->left)&&SameTree(t1->right,t2->right);
}
return 0;
}
TNode* Swap(Btree t){
    TNode *tmp;
if(t!=NULL){
tmp=t->right;
t->right=t->left;
t->left=tmp;
 Swap(t->left);
 Swap(t->right);
}

 return t;
}
TNode*CopyTree(Btree t1,Btree t2){

if(t1!=NULL){
    insertBST(t2,t1->data);
    CopyTree(t1->left,t2->left);
    CopyTree(t1->right,t2->left);
}
return t2;
}
