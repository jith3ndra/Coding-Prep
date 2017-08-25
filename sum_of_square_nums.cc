bool judgeSquareSum(int c) {
        if(c==0) return true;
        int start=0,end=sqrt(c),mid;
        while(start<=end){
            mid = start*start+end*end;
            if(mid==c) return true;
            else if(mid>c) end--;
            else start++;
        }
        return false;
    }
