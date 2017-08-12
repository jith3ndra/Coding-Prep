

int median(vector<int> nums){
        int s =0,e=nums.size()-1;
        if(nums.size()%2){
            return nums[(e-s)/2];
        }else
            return 0.5*(nums[(e-s)/2]+nums[(e-s)/2+1]);
    }
    int minMoves2(vector<int>& nums) {
        if(!nums.size())return 0;
        sort(nums.begin(),nums.end());
        int med = median(nums),res=0;
        if(nums.size()%2){
            for(int i=0;i<nums.size();i++){
                res+= abs(med-nums[i]);
            }
            return res;
        }else{
            for(int i=0;i<nums.size();i++){
                res+= abs(med-nums[i]);
            }
            return res;
        }
        
    }
