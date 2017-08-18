

vector<int> singleNumber(vector<int>& nums) {
        int rem=0,num1=0,num2=0;
        for(int i=0;i<nums.size();i++){
            rem^=nums[i];
        }
        for(int i=0;i<32;i++){
            if(rem & (1<<i)){
                rem = 1<<i;
                break;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i] & rem){
                num1^=nums[i];
            }else{
                num2^=nums[i];
            }
        }
        return {num1,num2};
    }
