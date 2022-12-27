
// Check wheather the given tree is BALANCED.....


pair<bool,int> solve(Node* root){
        if(root==NULL){
            pair<bool,int> p=make_pair(true,0);
            return p;
        }
        pair<bool,int> left=solve(root->left);
        pair<bool,int> right=solve(root->right);
        pair<bool,int> ans;
        ans.second=max(left.second,right.second)+1;
        if(abs(left.second-right.second)<=1 && left.first && right.first){
            ans.first=true;
        }
        else{
            ans.first=false;
        }
        return ans;
    }
    
    bool isBalanced(Node *root)
    {
        pair<bool,int> ans=solve(root);
        return ans.first;
    }