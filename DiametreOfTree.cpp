

// FINDING THE DIAMETER OF BINARY TREE......


pair<int,int> solve(Node* root){
        if(root==NULL){
            pair<int,int> p=make_pair(0,0);
            return p;
        }
        //(height,diameter)...
        pair<int,int> left=solve(root->left);
        pair<int,int> right=solve(root->right);
        pair<int,int> ans;
        int diameterLeft=left.second;
        int diameterRight=right.second;
        int opt=(left.first+right.first)+1;
        ans.first=max(left.first,right.first)+1;
        ans.second=max(diameterLeft,max(diameterRight,opt));
        return ans;
    }
    
    int diameter(Node* root) {
        pair<int,int> ans=solve(root);
        return ans.second;
    }