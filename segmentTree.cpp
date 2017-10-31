///segment tree(full binary tree) -- use the concept of divide & conquer
#include<iostream>
#include<climits>
using namespace std;

///build segment tree using the concept of array
void buildTree(int *tree, int *a, int s, int e, int index){
   ///base case
   if(s==e){
      tree[index]=a[s];
      return;
   }

   if(s>e){
      return;
   }

   int mid=(s+e)/2;
   buildTree(tree,a,s,mid,index*2);
   buildTree(tree,a,mid+1,e,(2*index+1));
   tree[index]=min(tree[2*index],tree[2*index+1]);
}

///query on the tree
int query(int *tree, int index, int s, int e, int qs, int qe){
    ///case-1:No Overlap
    if(qe<s||qs>e){
        return INT_MAX;
    }

    ///case-2:Complete Overlap
    if(qs>=s&&qe<=e){
        return tree[index];
    }

    ///case-3:Partial Overlap
    int mid=(s+e)/2;
    int leftTree = query(tree,2*index,s,mid,qs,qe);
    int rightTree = query(tree,(2*index+1),mid+1,e,qs,qe);
    return min(leftTree,rightTree);
}

///updation in segment tree
///case -1 :Node update
void nodeUpdate(int tree[], int index, int s, int e, int i, int value){
   //base case
   if(i<s||i>e){
      return;
   }
   ///reach to leaf node
   if(s==e){
     tree[index]=value;
     return;
   }
   int mid=(s+e)/2;
   nodeUpdate(tree,2*index,s,mid,i,value);
   nodeUpdate(tree,2*index+1,mid+1,e,i,value);
   tree[index]=min(tree[2*index],tree[2*index+1]);
}

///case-2 : Range update by increment of Value
void rangeUpadate(int tree[], int index, int s, int e, int qs, int qe, int value){
   ///base case
   if(qe<s||qs>e){
     return;
   }
   ///reach to leaf node
   if(s==e){
     tree[index] +=value;
     return;
   }
   int mid=(s+e)/2;
   rangeUpadate(tree,2*index,s,mid,qs,qe,value);
   rangeUpadate(tree,index,mid+1,e,qs,qe,value);
   tree[index]=min(tree[2*index],tree[2*index+1]);
}

int main(){
  int a[]={1,2,0,5};
  int n=sizeof(a)/sizeof(int);
  int s=0;
  int e=n-1;
  int *tree = new int[4*n+1];
  for(int i=0;i<4*n+1;i++){
    tree[i]=-1;
  }
  int index = 1;
  buildTree(tree,a,s,e,index);
  for(int i=0;i<4*n+1;i++){
    cout<<tree[i]<<" ";
  }
  cout<<"Enter the number of query to be done on tree"<<endl;
  int no_of_query;
  cin>>no_of_query;
  while(no_of_query>0){
    int qs,qe;
    cout<<"Enter the start & end range of query"<<" ";
    cin>>qs>>qe;
    int minData = query(tree,index,s,e,qs,qe);
    cout<<"Min element in the range"<<" "<<minData<<endl;
  }
  cout<<"Enter the index of array & value"<<endl;
  int i,value;
  cin>>i>>value;
  nodeUpdate(tree,index,s,e,i,value);
  cout<<endl;
  cout<<"Range Update"<<endl;
  int qs1,qe1,value1;
  cin>>qs1>>qe1>>value1;
  rangeUpadate(tree,index,s,e,qs1,qe1,value1);
  return 0;
}
