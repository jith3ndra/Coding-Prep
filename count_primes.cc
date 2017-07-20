


unordered_map<int,int> map1;
    int is_prime(int n){
        if(n==2) return true;
        if(n<=2 || n%2==0) return false;
        for(int i=3;i<=sqrt(n);i+=2){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
public:
    int countPrimes(int n) {
#if 0
        if(n<=2) return 0;
        int ctr = 1;
        for(int i=3;i<n;i++){
            if(is_prime(i))ctr++;
        }
        return ctr;
#endif
        vector<int> primes(n+1,1);
        primes[0]=0;primes[1]=0;primes[n]=0;
        for(int i=2;i<=sqrt(n);i++){
            if(primes[i]){
                for( int j=i*2;j<=n;j+=i){
                    primes[j]=0;
                }
            }
        }
        return count(primes.begin(),primes.end(),1);
    }
