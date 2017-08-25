

vector<int> ary,ary1;
public:
    Solution(vector<int> nums) {
        ary=nums;
        ary1=nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return ary;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for(int i=ary1.size();i>=1;i--){
            swap(ary1[i-1],ary1[rand()%i]);
        }
        return ary1;
    }
