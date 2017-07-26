

int findLongestChain(vector<vector<int>>& pairs) {
        if(!pairs.size() || !pairs[0].size()) return 0;
        sort(pairs.begin(),pairs.end(),[](vector<int> pairs1, vector<int> pairs2){return pairs1[1] < pairs2[1] || pairs1[1]==pairs2[1] && pairs1[0]< pairs2[0];});
        int temp=1,res = 1,end = pairs[0][1];
        for(int i=1;i<pairs.size();i++){
            if(end < pairs[i][0]){
                end = pairs[i][1];
                temp++;
            }
        }
         res = max(res,temp);
        return res;
    }
