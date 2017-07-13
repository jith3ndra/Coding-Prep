



    vector<string> summaryRanges(vector<int>& nums) {
        if(!nums.size()) 
        return {};
        vector<string> res;bool flag;string str="";
        for(int i=0;i<nums.size();i++){
            flag = false;
            if(!str.size()){
                str +=to_string(nums[i])+"->";
                flag = true;
            }
            if( i < nums.size()-1 && nums[i] == nums[i+1]-1 ){
                continue;
            }else{
                if(flag){
                    res.push_back(str.substr(0,str.size()-2));
                }else{
                    str+=to_string(nums[i]);
                    res.push_back(str);
                }    
                str = "";
            }
        }
        if(str.size()) {
            str+=to_string(nums.back());
            res.push_back(str);
        }
        return res;
    }
