///binary search tree(BST)

#include<iostream>
#include<queue>
#include<cmath>
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

///insertation in BST

Tnode *bstInsert(Tnode *&root,int d){
    if(root==NULL){
        root=new Tnode(d);
        return root;
    }

    if(root->data<d){
      root->T_right = bstInsert(root->T_right,d);
      return root;
    }
    else{
        root->T_left = bstInsert(root->T_left,d);
        return root;
    }
 }

void takeInput(Tnode *&root){
    int data;
    cin>>data;
    while(data!=-1){
        bstInsert(root,data);
        cin>>data;
    }
}

///advance level order print of BST
void print(Tnode *root){
  if(root==NULL){
    cout<<"Tree does't exit"<<endl;
  }

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
        q.pop();
        cout<<f->data<<" ";
        if(f->T_left){
            q.push(f->T_left);
        }
        if(f->T_right){
            q.push(f->T_right);
        }
    }
  }
}

///search key is present in the tree or not
bool searchKey(Tnode *root,int key){
    if(root==NULL){
        return false;
    }

    if(root->data==key){
        return true;
    }
    else if(root->data<key){
       return searchKey(root->T_right,key);
    }
    else{
       return searchKey(root->T_left,key);
    }
 }

///check given BST is height balance or not
class myPair{
   public :
    int height;
    bool isBalance;
};

myPair heightBalance(Tnode *root){
    myPair p;
    if(root==NULL){
        p.height=0;
        p.isBalance = true;
        return p;
    }
    myPair leftTree = heightBalance(root->T_left);
    myPair rightTree = heightBalance(root->T_right);

    int diff = abs(leftTree.height-rightTree.height);
    if(diff<=1&&leftTree.isBalance&&rightTree.isBalance){
        p.isBalance = true;
    }
    else{
        p.isBalance = false;
    }

    p.height = 1 + max(leftTree.height,rightTree.height);
    return p;
}

Tnode *minNode(Tnode *root){
   while(root->T_left!=NULL){
     root = root->T_left;
   }
   return root;
}

///deletion in BST
Tnode *deleteNode(Tnode *&root,int key){
   if(root!=NULL){
        if(root->data==key){
          ///case 1(ZERO CHILD)
        if(root->T_left==NULL&&root->T_right==NULL){
            delete root;
            return NULL;
          }

         ///case 2(ONE CHILD)
         else if(root->T_left!=NULL&&root->T_right==NULL){
            Tnode *temp = root->T_left;
            delete root;
            return temp;
         }

         else if(root->T_left==NULL&&root->T_right!=NULL){
            Tnode *temp = root->T_right;
            delete root;
            return temp;
         }

         ///case 3(THREE CHILD)
         else{
            Tnode *replacementNode = minNode(root->T_right);
            root->data = replacementNode->data;
            root->T_right=deleteNode(root->T_right,replacementNode->data);
            return root;
         }
        }
    else if(root->data<key){
        root->T_right = deleteNode(root->T_right,key);
        return root;
    }
    else{
        root->T_left = deleteNode(root->T_left,key);
        return root;
    }
   }
}

int main(){
  Tnode *root = NULL;
  takeInput(root);
  print(root);
  cout<<endl;
  int key;
  cout<<"Enter the key value want to search"<<endl;
  cin>>key;
  bool result = searchKey(root,key);
  if(result){
    cout<<"Key is present in the tree"<<endl;
  }
  else{
    cout<<"Key is not present"<<endl;
  }
  cout<<"Check BST is height balance or not";
  myPair p = heightBalance(root);
  if(p.isBalance){
    cout<<"Yes";
  }
  else{
    cout<<"No";
  }
  cout<<endl;
  int k;
  cin>>k;
  cout<<"Delete the node from BST"<<endl;
  deleteNode(root,k);
  cout<<endl;
  print(root);
  return 0;
}

