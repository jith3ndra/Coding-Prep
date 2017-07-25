




    int gma(vector<vector<int>> &ary,int start,int end){
        if(start>=end) return 0;
        if(ary[start][end]!=0) return ary[start][end];
        int temp =0,res=INT_MAX;
        for(int i=start;i<=end;i++){
            temp = i+ max(gma(ary,start,i-1),gma(ary,i+1,end));
            res = min(res,temp);
        }
        ary[start][end] = res;
        return ary[start][end];
    }
    int getMoneyAmount(int n) {
        vector<vector<int>> ary1(n+1,vector<int>(n+1,0));
        return gma(ary1,1,n);
    }
