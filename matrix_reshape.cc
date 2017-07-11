



    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        
        if( r*c != nums.size() * nums[0].size()){
            vector<vector<int>> res  = nums;
            return res;
        }
        int ctr=0;
        vector<vector<int>> res (r,vector<int>(c,0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                
                res[i][j] = nums[(ctr)/nums[0].size()][(ctr)%nums[0].size()];
                ctr++;
            }
        }
        return res;
    }
