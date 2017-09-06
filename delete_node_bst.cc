TreeNode* deleteNode(TreeNode* root, int key) {
        if(root){
            if(root->val==key){
                if(root->left){
                    TreeNode* temp = root->left;
                    while(temp->right){
                        temp = temp->right;
                    }
                    root->val = temp->val;
                    root->left = deleteNode(root->left,temp->val);
                }else if(root->right){
                    TreeNode* temp = root->right;
                    while(temp->left){
                        temp = temp->left;
                    }
                    root->val = temp->val;
                    root->right = deleteNode(root->right,temp->val);
                }else{
                    free(root);
                    return NULL;
                }
            }else if(root->val<key){
                root->right = deleteNode(root->right,key);
            }else{
                root->left = deleteNode(root->left,key);
            }
            return root;
        }
        return NULL;
    }
