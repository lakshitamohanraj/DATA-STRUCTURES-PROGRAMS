#include <iostream>
using namespace std;

struct Node{
    int key;
    struct Node* left;
    struct Node* right;
    int height;
};

int getHeight(struct Node* n){
    if(n==NULL) return 0;
    return n->height;
}
int max(int a , int b){
    return a>b? a:b;
}
struct Node* createNode(int key){
  struct Node* node=(struct Node*)malloc(sizeof(struct Node));
  node->key=key;
  node->left=node->right=NULL;
  node->height=1;

  return node;
}

int getBalanceFactor(struct Node* n){
    if(n==NULL)
        return 0;
    return getHeight(n->left)-getHeight(n->right);    
}

struct Node* rightRotate(struct Node* y){
     struct Node* x=y->left ;
    struct Node* T2=x->right;

    x->right=y;
    y->left=T2;

y->height=max(getHeight(y->right) , getHeight(y->left))+1;
x->height=max(getHeight(y->right) , getHeight(y->left))+1;

return x; //root

}


struct Node* leftRotate(struct Node* x){
     struct Node* y=x->right ;
    struct Node* T2=y->left;

    y->left=x;
    x->right=T2;

y->height=max(getHeight(y->right) , getHeight(y->left))+1;
x->height=max(getHeight(y->right) , getHeight(y->left))+1;

return y;

}

struct Node* insert(struct Node* node,int key){
    if(node==NULL)
    return createNode(key);

    if(key< node->key)
       node->left=insert(node->left,key);
    else if(key > node->key)
        node->right=insert(node->right,key);


     return node;
    
    node->height = 1+ max(getHeight(node->right),getHeight(node->left)); //adding cuz after inserting a node (leaf node) ??
    int bf=getBalanceFactor(node);

    //left left case

       if(bf>1 && key< node->left->key){
        return rightRotate(node);
       }
    //right right case
    if(bf< -1 && key > node->right->key){
       return leftRotate(node);
    }
    //left right case LR
    if(bf > 1 && key > node->left->key){
        node->left = leftRotate(node->left);
       return rightRotate(node);
    }
    //right left case RL
    if(bf< -1 && key < node->right->key){ // if right side has more nodes bf <-1
        node->right=rightRotate(node->right);
       return leftRotate(node);
    }
    return node;
}

void preorder(struct Node* node){
    if(node==NULL) return ;
    cout<<node->key<<" ";
    preorder(node->left);
    preorder(node->right);
}
int main(){

    struct Node* root =NULL;
    root=insert(root,1);
    root=insert(root,2);
    root=insert(root,4);
    root=insert(root,5);
    root=insert(root,6);
    root=insert(root,3);

    preorder(root);
    return 0;
}