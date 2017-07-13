



    bool canJump(vector<int>& nums) {
        if(!nums.size()) return false;
        int reach = 0, i;
        for(i=0;i<nums.size()-1;i++){
            if( i > reach){
                break;
            }
            reach = max(reach, i+nums[i]);
        }
        return reach >=nums.size()-1;
    }
