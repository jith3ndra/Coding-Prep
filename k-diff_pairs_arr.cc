


int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> map1; 
        if(k<0) return 0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            map1[nums[i]] = i;
        }
        
        for(int i=0;i<nums.size();i++){
            if(map1.count(nums[i]+k) && map1[nums[i]+k]!=i){
                count++;
                map1.erase(nums[i]+k);
            }
        }
        return count;
    }
