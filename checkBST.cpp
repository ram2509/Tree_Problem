///Check the given tree is BST or not
#include<iostream>
#include<bits/stdc++.h>
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

Tnode *insertToBST(Tnode *&root,int data){
    if(root==NULL){
        root=new Tnode(data);
        return root;
    }

    if(root->data<data){
       root->T_Right = insertToBST(root->T_Right,data);
       return root;
    }
    else{
        root->T_Left = insertToBST(root->T_Left,data);
        return root;
    }
}

void takeInput(Tnode *&root){
   int data;
   cin>>data;
   while(data!=-1){
    insertToBST(root,data);
    cin>>data;
   }
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

bool isBST(Tnode *root,int minV,int maxV){
    if(root==NULL){
        return true;
    }
    if(root->data>minV&&root->data<maxV&&isBST(root->T_Left,minV,root->data)&&isBST(root->T_Right,root->data,maxV)){
        return true;
    }
    return false;
}

int main(){
  Tnode *root = NULL;
  takeInput(root);
  cout<<"Print the BST"<<endl;
  print(root);
  cout<<endl<<endl;
  if(isBST(root,INT_MIN,INT_MAX)){
    cout<<"Above tree is BST"<<endl;
  }
  else{
    cout<<"Above tree is not BST";
  }

}
