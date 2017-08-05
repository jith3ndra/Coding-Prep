


    void ksmall(TreeNode* root,int &num,int &k,bool &flag){
        if(!root) return ;
        ksmall(root->left,num,k,flag);
        if(k==1 ){
            if(flag){
                flag = false;
                num = root->val;
            }
            return ;
        }else{
            k--;
        }
        ksmall(root->right,num,k,flag);
    }
    int kthSmallest(TreeNode* root, int k) {
        int num=0;bool flag = true;
        ksmall(root,num,k,flag);
        return num;
    }
