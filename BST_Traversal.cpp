#include <iostream>
using namespace std;

struct Node{
  int data;
  Node* left;
  Node* right;
  Node(int x){
    data=x;
    left=right=NULL;
  }
};

struct Node* createNode(int data){
    Node* newnode=new Node(data);
   return newnode;
} 
void preorder(struct Node* root){
    if(root==NULL) return ;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct Node* root){
  if(root==NULL) return ;
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}
void postorder(struct Node* root){
   if(root==NULL){
    return ;
   }
   postorder(root->left);
   postorder(root->right);
   cout<<root->data<<" ";
}

int main(){
  struct Node* root=NULL;
  root=createNode(4);
  root->left=createNode(5);
  root->right=createNode(10);
  root->left->left=createNode(7);
  root->left->right=createNode(8);
  root->right->right=createNode(1);

cout<<"PREORDER FORM:"<<endl;

preorder(root);
cout<<endl;
cout<<"INORDER FORM:"<<endl;

inorder(root);
cout<<endl;
cout<<"POSTORDER FORM:"<<endl;

postorder(root);

}