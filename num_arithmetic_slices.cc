int numberOfArithmeticSlices(vector<int>& A) {
        int count =0,sum=0;
        for(int i=1;i<(int)A.size()-1;i++){
            if(A[i-1]-A[i] == A[i]-A[i+1]){
                count+=1;
                sum+=count;
            }else{
                count=0;
            }
        }
        return sum;
    }
