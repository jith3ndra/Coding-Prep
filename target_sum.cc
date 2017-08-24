

   
    int subset_sum(vector<int>& nums,int S){
        vector<int> res(S+1,0);
        res[0]=1;
        for(int i=0;i<nums.size();i++){
            for(int j=S;j>=0;j--){
                if(j>=nums[i])
                    res[j]+=res[j-nums[i]];
            }
        }
        return res.back();
    }
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if(nums.size()==0) return 0;int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(S>sum || (S+sum)%2) return 0;
        return subset_sum(nums,(S+sum)/2);
    }
