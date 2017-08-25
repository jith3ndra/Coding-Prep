

int bin_sea(int i,vector<int> nums){
        int start =0,end = nums.size()-1,mid;
        while(start<=end){
            mid = (start+end) /2;
            if(nums[mid]==i) return mid;
            else if(nums[mid]
                   > i) end = mid-1;
            else start = mid+1;
        }
        return -1;
    }
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<int> res(nums);
        vector<string> res1;
        sort(res.begin(),res.end());
        for(int i=0;i<nums.size();i++){
            int n = bin_sea(nums[i],res);
            if(n==(int)(nums.size()-1)) res1.push_back("Gold Medal");
            else if(n==(int)(nums.size()-2)) res1.push_back("Silver Medal");
            else if(n==(int)(nums.size()-3)) res1.push_back("Bronze Medal");
            else{
                res1.push_back(to_string(nums.size()-n));
            }
        }
        return res1;
    }
