

int findDuplicate(vector<int>& nums) {
        if(!nums.size()) return -1;
        int start =0,end = nums.size()-1,mid;
        while(start<end){
            mid = start+(end-start)/2;
            int count =0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]<=mid){
                    count++;
                }
            }
            if( count<= mid){
                start = mid+1;
            }else{
                end = mid;
            }
        }
        return start;
    }
