


    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int l=0,r=0;
        TreeNode* left1 = root->left,*right1 = root->right;
        while(left1){
            left1=left1->left;
            l++;
        }
        while(right1){
            right1=right1->right;
            r++;
        }
        if(l==r) return pow(2,l+1)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
