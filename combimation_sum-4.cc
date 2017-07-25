

unordered_map<int,int> map1;
    int cs4(vector<int>& nums, int target){
        int res =0;
        if(map1.count(target))return map1[target];
        if(!target){
            return 1;
        }else{
            for(int i=0;i<nums.size();i++){
                if(nums[i] <=target){
                   res+= cs4(nums,target-nums[i]); 
                }
            }
        }
        map1[target]=res;
        return res;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        int res=0;
        res = cs4(nums,target);
        return res;
    }
