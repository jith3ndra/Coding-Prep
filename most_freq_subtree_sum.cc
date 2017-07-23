



    unordered_map<int,int> map1;
    int find_freq_tree_sum(TreeNode* root){
        if(!root) return 0;
        if(!root->left && !root->right){
            map1[root->val]++;
            return root->val;
        }
        int left = 0,right=0;
        if(root->left){
            left = find_freq_tree_sum(root->left);
        }
        if(root->right){
            right = find_freq_tree_sum(root->right);
        }
        map1[left+right+root->val]++;
        return left+right+root->val;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        find_freq_tree_sum(root);
        vector<int> res;int max_freq = 0;
        for(auto i=map1.begin();i!=map1.end();++i){
            max_freq = max(max_freq,i->second);
        }
        for(auto i=map1.begin();i!=map1.end();++i){
            if(i->second == max_freq){
                res.push_back(i->first);
            }
        }
        return res;
    }
