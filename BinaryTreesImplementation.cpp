#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* buildTree(Node* root){
    cout<<"Enter the data root: "<<endl;
    int data;
    cin>>data;
    root=new Node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter the data for left of: "<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter the data for right of: "<<data<<endl;
    root->right=buildTree(root->right);
    return root;
}

void buildTreeFromLevelOrder(Node* &root){
    queue<Node*> q;
    cout<<"Enter the data for root Node: "<<endl;
    int data;
    cin>>data;
    root=new Node(data);
    q.push(root);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        cout<<"Enter the data for left of: "<<temp->data<<endl;
        int lft;
        cin>>lft;
        cout<<"Enter the data for right of: "<<temp->data<<endl;
        int rght;
        cin>>rght;
        if(lft!=-1){
            temp->left=new Node(lft);
            q.push(temp->left);
        }
        if(rght!=-1){
            temp->right=new Node(rght);
            q.push(temp->right);
        }
    }
}

void levelOrderTraverse(Node* &root){
    
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        if(temp!=NULL){
            cout<<temp->data<<"  ";
            if(temp->left){
                q.push(temp->left);
            }
           if(temp->right){
                q.push(temp->right);
            }
        }
        else{
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
    }
}

void inOrderTraversal(Node* root){
    
    if(root==NULL){
        return;
    }
    inOrderTraversal(root->left);
    cout<<root->data<<"  ";
    inOrderTraversal(root->right);
}

void preOrderTraversal(Node* root){
    
    if(root==NULL){
        return;
    }
    cout<<root->data<<"  ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
    
}

void postOrderTraversal(Node* root){
    
    if(root==NULL){
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<"  ";
}


int main(){
    Node* root=NULL;
    buildTreeFromLevelOrder(root);
    cout<<endl;
    cout<<"Printing levelOrderTraverse...."<<endl;
    levelOrderTraverse(root);
    cout<<endl;
    cout<<"Printing inOrderTraversal...."<<endl;
    inOrderTraversal(root);
    cout<<endl;
    cout<<endl;
    cout<<"Printing preOrderTraversal...."<<endl;
    preOrderTraversal(root);
    cout<<endl;
    cout<<endl;
    cout<<"Printing postOrderTraversal...."<<endl;
    postOrderTraversal(root);


}