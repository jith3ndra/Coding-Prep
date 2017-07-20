

int findLHS(vector<int>& nums) {
        if(nums.size()<=1) return 0;
        unordered_map<int,int> map1;
        for(int i=0;i<nums.size();i++){
            map1[nums[i]]++;
        }
        
        int len=INT_MIN,max_len = INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(map1[nums[i]-1]!=0 ){
                //cout << "**"<<endl;
                len = map1[nums[i]-1]+ map1[nums[i]];
            }
            max_len = max(len,max_len);
        }
        return max_len==INT_MIN ? 0 : max_len;
    }
