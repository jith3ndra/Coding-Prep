

int Solution::majorityElement(const vector<int> &A) {
    int count=0,res=0;
    for(int i=0;i<A.size();i++){
        if(res==A[i]){
            count++;
        }else if(count){
            count--;
        }else{
            res = A[i];
            count=1;
        }
    }
    return res;
}
