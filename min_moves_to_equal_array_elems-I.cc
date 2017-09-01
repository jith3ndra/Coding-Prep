

int minMoves(vector<int>& nums) {
        int sum = 0,n=nums.size(),min1=INT_MAX;
        for(int i=0;i<n;i++){
            min1 = min(min1,nums[i]);
            sum+=nums[i];
        }
        return sum-n*min1;
    }
