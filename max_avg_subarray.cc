


    double findMaxAverage(vector<int>& nums, int k) {
        if(!nums.size() || k<=0) return 0;
        double avg=0,max_avg=INT_MIN;
        for(int i=0;i<k;i++){
            avg += nums[i];
        }
        max_avg = avg/k;
        for(int i=k;i<nums.size();i++){
            avg += nums[i] - nums[i-k];
            max_avg = max(max_avg,avg/k);
        }
        return max_avg;
    }
