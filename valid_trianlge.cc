//sort them and apply the a+b>c in that order. cis the largest side.

int triangleNumber(vector<int>& nums) {
        int res = 0;
        sort(nums.begin(),nums.end());
        for(int i=nums.size()-1;i>=2;i--){
           int start = 0,end = i-1;
            while(start<end){
                if(nums[start]+nums[end]>nums[i] ){
                    res += (end-start) ;
                  end--;
                }else
                    start++;
            }
            cout << nums[i]<<" "<< res << endl;
        }
        return res;
    }
