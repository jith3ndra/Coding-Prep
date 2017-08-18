


int findMaximumXOR(vector<int>& nums) {
        int mask=0,max=0;
        for(int i=31;i>=0;i--){
            mask = mask | 1<<i;
            unordered_set<int> set1;
            for(int i=0;i<nums.size();i++){
                set1.insert(nums[i]&mask);
            }
            int temp = max | 1<<i;
            for(auto i=set1.begin();i!=set1.end();++i){
                if(set1.count(temp ^ *i)){
                    max = temp;
                    break;
                }
            }
        }
        return max;
    }
