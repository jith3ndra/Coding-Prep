int rob1(vector<int>& nums) {
        int odd=0,even=0;
        for(int i=0;i<nums.size();i++){
            if(i%2){
                odd = max(even,odd+nums[i]);
            }else{
                even = max(odd,even+nums[i]);
            }
        }
        return max(odd,even);
    }

// house robber-2
    
    int hr1(vector<int> nums,int start,int end){
        int odd=0,even=0;
        for(int i=start;i<=end;i++){
            if(i%2){
                odd = max(even,odd+nums[i]);
            }else{
                even = max(odd,even+nums[i]);
            }
        }
        return max(odd,even);
    }
    int rob2(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        return max(hr1(nums,0,nums.size()-2),hr1(nums,1,nums.size()-1));
    }
