
int lcs(string w1,string w2){
        vector<vector<int>> res(w1.size()+1,vector<int>(w2.size()+1,0));
        
        for(int i=0;i<=w1.size();i++){
            for(int j=0;j<=w2.size();j++){
                if(i==0 || j==0) res[i][j]=0;
                else if(w1[i-1]==w2[j-1]){
                    res[i][j] = 1+res[i-1][j-1];
                }else{
                    res[i][j] = max(res[i][j-1],res[i-1][j]);
                }
            }
        }
        return res.back().back();
    }
    int minDistance(string word1, string word2) {
        
        int len = lcs(word1,word2);
        return abs(len - (int)word1.size()) + abs(len - (int)word2.size());
    }
