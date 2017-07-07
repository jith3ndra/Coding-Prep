

int subarraySum(vector<int>& nums, int k) {
        if(!nums.size())return 0;
        int sum=0,ctr=0;
        unordered_map<int,int> map1;
        map1[0]++;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            ctr +=map1[sum-k];
            
            map1[sum]++;
        }
        return ctr;
    }
