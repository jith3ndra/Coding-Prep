


 int removeDuplicates(vector<int>& nums) {
        int res=0;bool dup_found= false;
        for(int i=0;i<nums.size();i++){
            if(!res || nums[res-1]!=nums[i] || !dup_found){
                nums[res]=nums[i];
                if(res && nums[res-1]==nums[res])
                    dup_found =true;
                else if(res && nums[res-1]!=nums[res]){
                    dup_found = false;
                }
                res++;
            }   
        }
        return res;
    }
