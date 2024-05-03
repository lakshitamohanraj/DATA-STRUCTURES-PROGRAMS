#include <iostream>
using namespace std;

struct BstNode{
  int data;
  BstNode* left;
  BstNode* right;
};
BstNode* getNewNode(int data){
    BstNode* newnode=(struct BstNode*)malloc(sizeof(struct BstNode)); //or new BstNode()
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
BstNode* Insert(BstNode* root,int data){
    if(root==NULL){
        root=getNewNode(data);
        return root;
    }
    else if(data<=root->data){
          root->left=Insert(root->left,data);
          return root;
    }
    else{
       root->right=Insert(root->right,data);
       return root;
    }
}
bool Search(BstNode* root,int data){
    if(root==NULL) return false;
    else if (root->data==data) return true;
    else if(root->data>=data) return Search(root->left,data);
    else return Search(root->right,data);
}
BstNode* FindMin(BstNode* root){
  if(root==NULL){
    cout<<"Error tree is null"<<endl;
    return NULL;
  }
  else if(root->left==NULL) 
  return root;

  return FindMin(root->left); //it keeps goes on and returns to the previous call
}
BstNode* FindMax(BstNode* root){
  if(root==NULL){
    cout<<"Error tree is null"<<endl;
    return NULL ;
  }
  else if(root->right==NULL)
  return root;

  return FindMax(root->right);
}

struct BstNode* Delete(struct BstNode* root, int data){
  if(root==NULL) return root;

  else if(data < root->data) {
    root->left=Delete(root->left,data);}

  else if(data > root->data) {
    root->right=Delete(root->right,data);  //if the root ->data is ==data it goes to the next case to check the left anf right
  }
  else{ // deleting the node
    //Case 1 : no child
    if(root->left==NULL && root->right==NULL)
    {  delete root;
        root= NULL;
        return root;
    }
    //Case 2 : one child
    else if(root->left==NULL){
      struct BstNode * temp=root;
      root=root->right;
      delete temp;
      return root;
    }
    else if(root->right==NULL){
      BstNode* temp=root;
      root=root->left;
      delete temp;
      return root;
    }
  //Case 3 : 2 children
  else {
    struct BstNode* temp=FindMin(root->right); // get max in left or get min in right
    root->data=temp->data; //changing 
    root->right=Delete(root->right,temp->data);  //return is null
  }
 }
} 
void preorder(BstNode * root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
  BstNode* rootptr;
  rootptr=NULL;
  rootptr=Insert(rootptr,15);
  rootptr=Insert(rootptr,20);
  rootptr=Insert(rootptr,10);
  rootptr=Insert(rootptr,25);
  preorder(rootptr);
  if(Search(rootptr,15)) cout<<"Found it!!"<<endl;
  else cout<<"Not Found !1"<<endl;

cout<<"Maximum value in the BST is "<<FindMax(rootptr)->data<<endl;
cout<<"Minimum value in the BST is "<<FindMin(rootptr)->data<<endl;

rootptr=Delete(rootptr,10);
 if(Search(rootptr,10)) cout<<" 10 -Found it!!"<<endl;
  else cout<<" 10 -Not Found !"<<endl;


return 0;
}