


bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size()==0) return 0;
            for(int i=0;i<nums.size();i++){
                if(i && nums[i]+nums[i-1]==0){
                    return true;
                }
            }
            if(k==0)
            return false;

       unordered_map<int,int> map1;
        int sum =0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(i && sum%k==0){
                return true;
            }
            if( map1.count(sum%k) && i>1+map1[sum%k]){
                return true;
            }
            map1[sum%k] = i;
        }
