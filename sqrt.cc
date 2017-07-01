int mySqrt(int A) {
         if(A==1 || A==0){
        return A;
    }else{
        unsigned long long start =1,end=A,mid;
        while(start<=end){
            mid = start+(end-start)/2;
            if(mid*mid == A){
                return mid;    
            }else if(mid*mid <A){
                start = mid+1;
                if(start*start >A){
                    return mid;
                }
            }else{
                end = mid-1;
                if(end*end <A){
                    return end;
                }
            }
        }
    }
  return 0;
    }
