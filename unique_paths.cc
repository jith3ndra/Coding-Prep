


    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        if(og.back().back()==1 || !og.size()) return 0;
        
        vector<vector<int>> ary(og.size(),vector<int>(og[0].size(),0));
        int m = ary.size(),n = ary[0].size();
        ary[m-1][n-1] =1;
        for(int i=m-2;i>=0;i--){
            if(og[i][n-1]!=1){
                ary[i][n-1] =1;
            }else{
                break;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(og[m-1][i]!=1){
                ary[m-1][i] =1;
            }else{
                break;
            }
        }
        for( int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                if(og[i][j]!=1){
                    ary[i][j] += (ary[i+1][j] +ary[i][j+1]);
                }
            }
        }
        return ary[0][0];
    }
