



    bool canJump(vector<int>& nums) {
        if(!nums.size()) return false;
        int reach = 0;
        for(int i=0;i<nums.size()-1;i++){
            if( i > reach){
                break;
            }
            reach = max(reach, i+nums[i]);
        }
        return i==nums.size()-1;
    }
