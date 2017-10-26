///BST to Linked list
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
}

///BST to LL
class treeToLL{
   public :
       Tnode *head;
       Tnode *tail;
};

treeToLL convertToLL(Tnode *&root){
     treeToLL l;
     if(root==NULL){
        l.head = NULL;
        l.tail = NULL;
        return l;
     }
     if(root->T_Left==NULL&&root->T_Right==NULL){
        l.head = l.tail = root;
     }
     else if(root->T_Left!=NULL&&root->T_Right==NULL){
        treeToLL leftTree = convertToLL(root->T_Left);
        leftTree.tail->T_Right=root;
        l.head=leftTree.head;
        l.tail = root;
     }
     else if(root->T_Left==NULL&&root->T_Right!=NULL){
        treeToLL rightTree = convertToLL(root->T_Right);
        root->T_Right=rightTree.head;
        l.head=root;
        l.tail =rightTree.tail;
     }
     else{
        treeToLL leftTree = convertToLL(root->T_Left);
        treeToLL rightTree = convertToLL(root->T_Right);
        leftTree.tail->T_Right=root;
        root->T_Right = rightTree.head;
        l.head = leftTree.head;
        l.tail = rightTree.tail;
     }
     return l;
}

int main(){
  Tnode *root = NULL;
  takeInput(root);
  cout<<"Print the BST"<<endl;
  print(root);
  cout<<endl<<endl;
  cout<<"Convert the BST into Linked list"<<endl;
  treeToLL l = convertToLL(root);
  Tnode *temp = l.head;
  while(temp!=NULL){
    cout<<temp->data<<"-->";
    temp=temp->T_Right;
  }
  cout<<"NULL";

}
