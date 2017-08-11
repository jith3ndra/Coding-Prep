

int maxRotateFunction(vector<int>& A) {
        if (!A.size()) return 0;
        int sum=0,f = 0,maxf;
        for(int i=0;i<A.size();i++){
            f+= i*A[i];
            sum+=A[i];
        }
        maxf= f;
        for(int i=A.size()-1;i>=1;i--){
            f += sum- A.size()*A[i];
            maxf = max(maxf,f);
        }
        return maxf;
    }
