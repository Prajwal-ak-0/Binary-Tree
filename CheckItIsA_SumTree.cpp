

// CHECK A GIVEN TREE IS A SUM TREE.......

pair<bool,int> solve(Node* root){
        if(root==NULL){
            pair<bool,int> p=make_pair(true,0);
            return p;
        }
        if(root->left==NULL && root->right==NULL){
            pair<bool,int> p=make_pair(true,root->data);
            return p;
        }
        pair<bool,int> left=solve(root->left);
        pair<bool,int> right=solve(root->right);
        pair<bool,int> ans;
        bool cond=left.second+right.second==root->data;
        if(cond&&left.first&&right.first){
            ans.first=true;
        }
        else{
            ans.first=false;
        }
        ans.second=left.second+right.second+root->data;
        return ans;
    }
    
    bool isSumTree(Node* root)
    {
         pair<bool,int> ans=solve(root);
         return ans.first;
    }