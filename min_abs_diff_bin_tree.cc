

 void gmd(TreeNode* root, int &val,int &prev){
        if(root){
            gmd(root->left,val,prev);
            val = min(val,abs(root->val -prev));
            prev = root->val;
            gmd(root->right,val,prev);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        int val = INT_MAX,prev=INT_MAX;
        gmd(root,val,prev);
        return val;
    }
