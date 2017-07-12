
int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size()==0 || nums.size()==1) return 0;
        vector<int> res = nums;
        sort(res.begin(),res.end());
        int start=-1,end =-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i] != res[i]){
                start = i;
                break;
            }
        }
        
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i] != res[i]){
                end = i;
                break;
            }
        }
        if(start==-1 && end==-1) return 0;
        return (end-start+1);
        
    }


//O(n) time and O(1) space;


int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size()==0 || nums.size()==1) return 0;

        int max_violated_elem = INT_MIN,min_violated_elem = INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(i && nums[i-1] > nums[i]){
                min_violated_elem= min(nums[i],min_violated_elem);
            }
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(i && nums[i-1] > nums[i]){
                max_violated_elem= max(nums[i-1],max_violated_elem);
            }
        }
        
        int start =-1,end =-1;
        for(int i=0;i<nums.size();i++){
            if(start ==-1 && nums[i]> min_violated_elem) start = i;
            
        }
         for(int i=nums.size()-1;i>=0;i--){
             if(end ==-1 && nums[i] < max_violated_elem) end = i;
         }    
        if(end==start) return 0;
        return (end-start+1);
    }
