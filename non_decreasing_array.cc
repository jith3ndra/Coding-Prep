

 bool checkPossibility(vector<int>& nums) {
        if(nums.size()<=1)return true;
        int voil = 0,prev=nums[0];
        for(int i=1;i<nums.size();i++){
            if(prev <=nums[i]){ 
                prev = nums[i];
            }else if(voil==0){
                voil++;
                if(i>=2 && nums[i]>=nums[i-2]){
                   prev = nums[i];
                }else if (i<2)
                    prev = nums[i];
                else
                    prev = nums[i-1];
            }else{
                return false;
            }
        }
        return true;
    }
