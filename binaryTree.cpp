#include<iostream>
#include<queue>
using namespace std;

class Tnode{
  public:
   int data;
   Tnode *T_left;
   Tnode *T_right;

  Tnode(int d){
    data = d;
    T_left = NULL;
    T_right = NULL;
  }
};

///build tree using recursive method
Tnode *buildTree(){
  int data;
  cin>>data;
  if(data==-1){
    return NULL;
  }
  Tnode *n = new Tnode(data);
  n->T_left = buildTree();
  n->T_right = buildTree();
  return n;
}

///build tree using iterative method
void iterativeTree(Tnode *&root){
    int data;
    cin>>data;
    if(root==NULL&&data!=-1){
        root = new Tnode(data);
    }
    queue<Tnode*> q;
    q.push(root);
    while(!q.empty()){
        Tnode *f = q.front();
        q.pop();
        int c1,c2;
        cout<<"Enter the child node of"<<" "<<f->data<<" "<<endl;
        cin>>c1>>c2;
        if(c1!=-1){
            f->T_left = new Tnode(c1);
            q.push(f->T_left);
        }
        if(c2!=-1){
            f->T_right = new Tnode(c2);
            q.push(f->T_right);
        }
    }
}

///print the tree in level order
void advanceTree(Tnode *root){
  if(root==NULL){
    cout<<"Tree doesn't exit"<<endl;
  }
  queue<Tnode*> q1;
  q1.push(root);
  q1.push(NULL);
  while(!q1.empty()){
    Tnode *f = q1.front();
    if(f==NULL){
        q1.pop();
        cout<<endl;
        if(!q1.empty()){
            q1.push(NULL);
        }
    }
    else{
        q1.pop();
        cout<<f->data;
        if(f->T_left){
            q1.push(f->T_left);
        }
        if(f->T_right){
            q1.push(f->T_right);
        }
    }
  }
}

///Preorder Print
Tnode *preOrder(Tnode *root){
    if(root==NULL){
        return NULL;
    }
    preOrder(root->T_left);
    cout<<root->data<<" ";
    preOrder(root->T_right);
}

///postOrder
Tnode *postOrder(Tnode *root){
   if(root==NULL){
      return NULL;
   }
   postOrder(root->T_left);
   postOrder(root->T_right);
   cout<<root->data<<" ";
}

///InOrder
Tnode *inOrder(Tnode *root){
   if(root==NULL){
     return NULL;
   }
   cout<<root->data<<" ";
   inOrder(root->T_left);
   inOrder(root->T_right);
}

int main(){
   Tnode *root = NULL;
   //cout<<"Recursive tree"<<endl;
   //root = buildTree();
   cout<<"Iterative tree"<<endl;
   iterativeTree(root);
   advanceTree(root);
   cout<<endl;
   cout<<"Preorder print"<<endl;
   preOrder(root);
   cout<<endl;
   cout<<"PostOrder print"<<endl;
   postOrder(root);
   cout<<endl;
   cout<<"Inorder print"<<endl;
   inOrder(root);
   return 0;
}
