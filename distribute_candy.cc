


int Solution::candy(vector<int> &ratings) {
    int count=0;
    vector<int> res(ratings.size(),0);
    for(int i=0;i<ratings.size();i++){
        if(i!=0 && ratings[i]>ratings[i-1]){
            res[i] = res[i-1]+1;
        }else{
            res[i] = 1;
        }
        int j=i;
        while(j>0 && res[j]== res[j-1] && ratings[j]<ratings[j-1]){
            res[j-1]++;
            j--;
        }
    }
    for(int i=0;i<res.size();i++)count+=res[i];
    return count;
}
