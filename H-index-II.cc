

int hIndex(vector<int>& citations) {
        int res = 0;
        int start=0,end =citations.size()-1,mid,end1=citations.size()-1;
        while(start<=end){
            mid = (start+end)/2;
            //cout << mid<<endl;
            if( (mid==0 && citations[mid]>=(end1-mid+1) )|| (mid && citations[mid]>= (end1-mid+1) && citations[mid-1] <=(end1-mid+1)) ){
                res =(end1-mid+1) ;
                break;
            }else if((citations[mid]<(end1-mid+1))){
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
        return res;
    }
