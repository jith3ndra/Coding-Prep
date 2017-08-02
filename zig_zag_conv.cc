


    string convert(string s, int numRows) {
        if(numRows==1) return s;
        vector<vector<int>> res(numRows,vector<int>());
        string res1 ="";bool flag;int k=0;
        for(int i=0;i<s.size();i++){
            if(k==0){
                res[k].push_back(s[i]);
                k++;
                flag = true;
            }else if(k!=numRows-1){
                res[k].push_back(s[i]);
                if(flag){
                    k++;
                }else
                    k--;
            }else{
                flag = false;
                res[k].push_back(s[i]);
                k--;
            }
        }
        for(int i=0;i<res.size();i++){
            for(int j=0;j<res[i].size();j++){
                res1+=res[i][j];
            }
        }
        return res1;
    }
