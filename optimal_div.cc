


    string optimalDivision(vector<int>& nums) {
        if(!nums.size()) return "";
        string res = "";
        bool flag=false;
        if ( nums.size() > 2)flag =true;
        for(int i=0;i<nums.size();i++){
            res += to_string(nums[i]);
            if(i < nums.size()-1)
                res += "/";
            if(!i && flag)
                res += "(";
        }
        if(flag)
            res+= ")";
        return res;
    }
