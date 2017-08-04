


    int findMin(vector<int>& nums) {
        if(!nums.size()) return -1;
        int start = 0,end = nums.size()-1,mid;
        while(start<end){
            mid = start+(end-start)/2;
            if(nums[mid]>nums[end]){
                start = mid+1;
            }else{
                end = mid; 
            }
        }
        return nums[start];
    }
