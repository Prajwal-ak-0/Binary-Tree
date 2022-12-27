
// PROGRAMMEE TO FIND THE MAXIMUM HEIGHT OF THE TREE.....


int solve(struct Node* node,int height ){
        if(node==NULL){
            return 0;
        }
        int left=solve(node->left,height);
        int right=solve(node->right,height);
        height=max(left,right)+1;
        return height;
    }
    
    int height(struct Node* node){
        int height=0;
        return solve(node,height);
        
    }