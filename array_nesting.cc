
//mark the visited elements as -1;


 int arrayNesting(vector<int>& nums) {
        int res=0,temp,iter,iter2;
        for(int i=0;i<nums.size();i++) {
            temp =0;
            iter =i;
            while(nums[iter]!= -1){
                temp++;
                iter2 = nums[iter];
                nums[iter] = -1;
                iter = iter2;
            }
            res = max(res,temp);
        }   
        return res;
    }


