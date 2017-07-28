
    int longestPalindromeSubseq(string s) {
        if(s.size()<=1) return s.size();
        int n = s.size();
        vector<vector<int>> res (n,vector<int>(n,0));
        
        for(int i=n-1;i>=0;i--){
                res[i][i]=1;
            for(int j=i+1;j<n;j++){
                if(s[i]==s[j]){
                    res[i][j] = 2+res[i+1][j-1];
                }else{
                    res[i][j] = max(res[i+1][j],res[i][j-1]);
                }
            }
        }
        return res[0][n-1];
    }
