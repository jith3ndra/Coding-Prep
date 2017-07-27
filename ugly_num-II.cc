
    int nthUglyNumber(int n) {
        if(n<=0) return 0;
        vector<int> res(n,0);
        res[0]=1;int k1=0,k2=0,k3 =0;
        for(int i=1;i<n;i++){
            res[i] = min(res[k1]*2,min(res[k2]*3,res[k3]*5));
            if (res[i] == res[k1]*2)k1++;
            if (res[i] == res[k2]*3)k2++;
            if (res[i] == res[k3]*5)k3++;
        }
        return res.back();
    }
