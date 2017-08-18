

    int totalHammingDistance(vector<int>& nums) {
        int res=0;int n = nums.size(),count;
        for(int i=31;i>=0;i--){
            count = 0;
            for(int j=0;j<nums.size();j++){
                
                if(nums[j] & 1<<i){
                    count++;
                }
            }
            res+= (count* ( n - count));
        }
        return res;
    }
