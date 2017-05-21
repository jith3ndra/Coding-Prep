int maxDiff(Node *root, int k)
{
    if(!root) return k;
    else if(root && !root->left && !root->right) return root->key;
    else if(root->key < k){
        int p;
        if(root->right){
            p = maxDiff(root->right,k);
        }else{
            p = 0;
        }
        return (abs(p-k)>abs(k-root->key)?root->key:p);
    }
    else if(root->key>k){
        int p;
        if(root->left){
            p = maxDiff(root->left,k);
        }else{
            p = 0;
        }
        return (abs(p-k)>abs(k-root->key)?root->key:p);
    }
}
