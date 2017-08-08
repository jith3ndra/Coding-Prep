
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> res(n,INT_MAX);
        vector<int> count(primes.size(),0);
        res[0] =1;
        for(int i=1;i<res.size();i++){
            for(int j=0;j<primes.size();j++){
                res[i] = min(res[i],primes[j]*res[count[j]]);
            }
            for(int j=0;j<primes.size();j++){
                if(res[i] == primes[j]*res[count[j]] ){
                    count[j]++;
                }
            }
        }
        return res.back();
    }
