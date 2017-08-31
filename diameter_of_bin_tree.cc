


int dobt(TreeNode* root,int &val){
        if(!root) return 0;
        int left=0,right =0;
        if(root->left)
            left  = 1 + dobt(root->left,val);
        if(root->right)
            right = 1 + dobt(root->right,val);
        val = max(val,left+right);
        return max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int val=0;
        dobt(root,val);
        return val;
    }
