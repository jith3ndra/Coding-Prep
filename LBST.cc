bool lbst(struct node* root,int  n){
    int n1=0,n2=0;
    bool left,right;
    if(!root) return 0;
    else if(!root->left && !root->right) return 1;
    else if(root->left && !root->right ){
        right = true;n2=0;
        left = lbst(root->left,n1);
        if(root->val > root->left->val){
            n = n1+1;
        }else{
            n =1;
        }
    }else if(!root->left && root->right){
        left = true;n1=0;
        right = lbst(root->right,n2);
        if(root->val <= root->right->val){
            n = n2+1;
        }else{
            n =1;
        }
    }else{
        //bool left = lbst(root->left,n1),right = lbst(root->right,n2);
        if( root->val>root->left && root->val<=root->right && left && right){
            n = n1+n2+1;
        }else if((left && !right) || (!left && right)){
            n= max(n1,n2);
        }
        
    }
}
int largestBST(struct node *root)
{
    int n = 0;
    lbst(root,n);
    return n;
}

