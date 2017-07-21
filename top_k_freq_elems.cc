

 vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> res1(nums.size()+1,vector<int>({}));
        vector<int> res;
        unordered_map<int,int> map1;
        for(int i=0;i<nums.size();i++){
            map1[nums[i]]++;
        }
        for(auto i=map1.begin();i!=map1.end();++i){
            res1[i->second].push_back(i->first);
        }
        for(int i=res1.size()-1;i>=0;i--){
            for(int j=0;j<res1[i].size();j++){
                res.push_back(res1[i][j]);
                k--;
                if(!k) return res;
            }
        }
        
    }
