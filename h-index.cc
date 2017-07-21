

int hIndex(vector<int>& citations) {
        if(!citations.size()) return 0;
        sort(citations.begin(),citations.end());
        int res =0;int size = citations.size();
        for(int i=size-1;i>=0;i--){
            if(size - i <= citations[i] ){
                if (i  && citations[i-1]<= size-i){
                    return size -i;
                }else if(i==0){
                    return size;
                }
            }
        }
        return res;
    }
