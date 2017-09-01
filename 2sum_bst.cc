

TreeNode* search(int val,TreeNode* root){
        if(root){
            if(root->val==val) return root;
            if(root->val < val) return search(val,root->right);
            else
                return search(val,root->left);
        }
        return NULL;
    }
    void ft(TreeNode* root,bool&flag,TreeNode* temp,int k){
        if(root && !flag){
                ft(root->left,flag,temp,k);
                TreeNode* node = search(k-root->val,temp);
                if(node && node!=root){
                    flag = true;
                }else if(node && node->right && node->right->val == root->val){
                    flag = true;
                }
                ft(root->right,flag,temp,k);
        }
    }
    bool findTarget(TreeNode* root, int k) {
        bool flag = false;
        ft(root,flag,root,k);
        return flag;
    }
