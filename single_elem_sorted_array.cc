
int singleNonDuplicate(vector<int>& nums) {
        int start=0,end=nums.size()-1,mid;
        
        while(start<end){
            //cout << start << " " <<end<<endl;
            mid = (start+end)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]) return nums[mid];
            else if(nums[mid]==nums[mid+1] ){
                if( (mid)%2 )
                    end = mid;
                else
                    start = mid+1;
            }else{
                if( (mid)%2 )
                    start = mid+1;
                else
                    end = mid;
            }
        }
        
        return start<=nums.size()-1?nums[start]:nums[0];
    }
