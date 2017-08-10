

int sup_pow(int a,int b){
        a%=1337;
        int res=1;
        for(int i=1;i<=b;i++){
            res = (res*a )%1337;
        }
        return res;
    }
    int superPow(int a, vector<int>& b) {
        if(a==0) return 0;
        if(!b.size()) return 1;
        int last = b.back();
        b.pop_back();
        return sup_pow(superPow(a,b),10) * sup_pow(a,last) % 1337;
    }
