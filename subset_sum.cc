

    // approach for subset sum 
    // with just 1 elem what all sums can be formed
    // with 2 elems what all sums cna be formed ...
    // with i elems what all sums cna be formed..
    
    int subset_sum(vector<int>& nums,int S){
        vector<int> res(S+1,0);
        res[0]=1;
        for(int i=0;i<nums.size();i++){
            for(int j=S;j>=0;j--){
                if(j>=nums[i])
                    res[j]+=res[j-nums[i]];
            }
        }
        return res.back();
    }
