
// PROGRAMME TO FIND NO OF LEAF NODES IN A GIVEN BINARY TREE......

void solve(Node* root, int &count){
    if(root==NULL){
        return;
    }
    
    solve(root->left,count);
    if(root->left==NULL && root->right==NULL){
        count++;
    }
    solve(root->right,count);
}
int countLeaves(Node* root)
{
    int count=0;
    solve(root,count);
    return count;
    
}