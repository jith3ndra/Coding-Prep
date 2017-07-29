
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<=1) return nums.size();
        int res =2,k=0;
        
        while(k<nums.size() && nums[k]==nums[k+1])k++;
        if(k==nums.size()-1) return 1;
        bool pos = nums[k] < nums[k+1];
        for(int i=k+1;i+1<nums.size();i++){
            if( pos && nums[i] > nums[i+1]){
                res++;
                pos = !pos;
            }else if(!pos && nums[i] < nums[i+1]){
                res++;
                pos = !pos;
            }
        }
        return res;
    }
