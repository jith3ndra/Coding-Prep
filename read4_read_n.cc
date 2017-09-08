int read(char *buf, int n) {
        int count=0,val=0,n1=n;
        while(n>0){
            val = read4(buf+count);
            count+=val;
            n-=val;
            if(val<4){
                break;
            }
        }
        if(n<=0){
            return n1;
        }else{
            return count;
        }
    }
