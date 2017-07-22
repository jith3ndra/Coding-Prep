


    int findMaxLength(vector<int>& nums) {
        int ctr=0,res=0;
        unordered_map<int,int> map1;
        map1[0] =-1;
        for(int i=0;i<nums.size();i++){
            if(!nums[i]){
                ctr++;
            }else{
                ctr--;
            }
            //cout << ctr <<endl;
            if(map1.count(ctr)){
                res = max(res,i-map1[ctr]);
            }else{
                map1[ctr] = i;
                //cout << ctr<<endl;
            }
        }
        return res;
    }
