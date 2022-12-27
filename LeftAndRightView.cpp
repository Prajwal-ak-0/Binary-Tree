


// ->RIGHT VIEW OF THE TREE.....

void solve(Node* root, vector<int> &ans,int level){
        if(root==NULL){
            return;
        }
        if(ans.size()==level){
            ans.push_back(root->data);
        }
        solve(root->right,ans,level+1);
        solve(root->left,ans,level+1);
    }
    vector<int> rightView(Node *root)
    {
       vector<int> ans;
       solve(root,ans,0);
       return ans;
    }

// ->LEFT VIEW OF THE TREE.....

    void solve(Node* root, vector<int> &ans,int level){
        if(root==NULL){
            return;
        }
        if(ans.size()==level){
            ans.push_back(root->data);
        }
        solve(root->left,ans,level+1);
        solve(root->right,ans,level+1);
    }
    vector<int> rightView(Node *root)
    {
       vector<int> ans;
       solve(root,ans,0);
       return ans;
    }