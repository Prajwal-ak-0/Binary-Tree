



//BOUNADRY TRAVERSAL.....

// ->Traverse left part of the tree only......
void leftTraverse(Node* root, vector<int> &ans){
        if((root==NULL)||(root->left==NULL && root->right==NULL)){
            return;
        }
        ans.push_back(root->data);
        if(root->left){
            leftTraverse(root->left,ans);
        }
        else{
            leftTraverse(root->right,ans);
        }
    }
// ->Traverse all leaf node of the tree......

    void leafTraverse(Node* root,vector<int> &ans){
        // ->Order is important.....
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            ans.push_back(root->data);
            return;
        }
        
        leafTraverse(root->left,ans);
        leafTraverse(root->right,ans);
    }
// ->Traverse all right part of the tree.....    
    void rightTraverse(Node* root, vector<int> &ans){
        if((root==NULL) || (root->left==NULL && root->right==NULL)){
            return;
        }
        if(root->right){
            rightTraverse(root->right,ans);
        }
        else{
            rightTraverse(root->left, ans);
            
        }
        ans.push_back(root->data);
    }   
    

    vector<int> boundary(Node *root)
    {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        ans.push_back(root->data);
        leftTraverse(root->left,ans);
        leafTraverse(root->left,ans);
        leafTraverse(root->right,ans);
        rightTraverse(root->right,ans);
        return ans;
    }