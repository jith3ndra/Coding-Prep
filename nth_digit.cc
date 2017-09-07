int findNthDigit(int n) {
        int count=1,res=1;
        long num=9;
        while(n>count*num){
            n-= num*count;
            
            num*=10;
            count++;
            res*=10;
            
        }
        res+= (n-1)/count;
        string str= to_string(res);
        return (str[(n-1)%count]-'0');
}
