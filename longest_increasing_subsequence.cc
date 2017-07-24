    
    int bin_search(vector<int> res,int start,int end,int x){
        int mid;
        while(start<=end){
            mid = start + (end - start)/2;
            if(res[mid] == x ){
                return mid-1;
            }else if(res[mid] < x){
                start = mid+1;
                if(res[start] > x){
                    return mid;
                }
            }else{
                end = mid -1;
                if(res[end] < x){
                    return end;
                }
            }
        }
        
        return -1;
    }
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0 || nums.size()==1) return nums.size();
        vector<int> res (nums.size(),0);
        int len = 0;int j;
        for(int i=0;i<nums.size();i++){
            if(!len ){
                res[len++] = nums[i];
            }
            else if(res[len-1] < nums[i] || !nums[i] ){
                    res[len++] = nums[i];
            }else{
                j = bin_search(res,0,len,nums[i]);
                res[j+1] = nums[i]; 
            }    
        }
        return len;
    }
