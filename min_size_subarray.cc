


 
        int sum=0,start=0,res =INT_MAX;
        for( int i=0;i<nums.size();i++){
            sum +=nums[i];
            while(sum>=s){
                res  =  min(res, i-start+1);
                sum -= nums[start++];
            }
        }
        if(res==INT_MAX) return 0;
        return res;
