

int fpe(vector<int> &nums,int start,int end){
        int mid = start+(end-start)/2;
        if(start==end) return start;
        else if(start==end-1){
            return nums[start]>nums[end]?start:end;
        }else if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
            return mid;
        }
        else if(nums[mid]>nums[mid+1] ){
            return fpe(nums,start,mid-1);
        }else if(nums[mid]<nums[mid+1] ){ 
            return fpe(nums,mid+1,end);
        }
    }
int findPeakElement(vector<int>& nums) {
        return fpe(nums,0,nums.size()-1);
    }
