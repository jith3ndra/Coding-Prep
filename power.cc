double myPow(double x, int n) {
        if(n<0){
            x = 1/x;
            if(n==INT_MIN){
                if(x==1 || x== -1) return 1;
                else return 0;
            }else
            n *= -1;
        }
        if(n==0) return 1;
        if(n==1) return x;
        double res = 1;
        if(n%2==0){
            res = myPow(x,n/2);
            res = res*res;
        }else{
            res = myPow(x,n/2);
            res = res*res*x;
        }
        return res;
    }
