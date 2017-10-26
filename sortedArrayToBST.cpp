///Sorted Array to BST
#include<iostream>
#include<queue>
using namespace std;
class Tnode{
  public :
      int data;
      Tnode *T_Left;
      Tnode *T_Right;

      Tnode(int d){
        data = d;
        T_Left = NULL;
        T_Right = NULL;
      }
};

Tnode *arryTobst(int *a,int s,int e,Tnode *&root){
   if(s>e){
     return NULL;
   }
   int mid = (s+e)/2;
   root = new Tnode(a[mid]);
   root->T_Left=arryTobst(a,s,mid-1,root->T_Left);
   root->T_Right=arryTobst(a,mid+1,e,root->T_Right);
   return root;
}

void print(Tnode *root){
   queue<Tnode*> q;
   q.push(root);
   q.push(NULL);
   while(!q.empty()){
      Tnode *f = q.front();
      if(f==NULL){
        q.pop();
        cout<<endl;
        if(!q.empty()){
            q.push(NULL);
        }
      }
      else{
        cout<<f->data<<" ";
        q.pop();
        if(f->T_Left){
            q.push(f->T_Left);
        }
        if(f->T_Right){
            q.push(f->T_Right);
        }
      }
}
};

int main(){
  Tnode *root=NULL;
  int a[]={1,2,3,4,5,6,7,8,9,10};
  int s = 0;
  int e = sizeof(a)/sizeof(int)-1;
  root = arryTobst(a,s,e,root);
  cout<<"Print the BST"<<endl;
  print(root);
}
