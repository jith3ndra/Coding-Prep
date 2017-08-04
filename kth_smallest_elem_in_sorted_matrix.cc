

int kthSmallest(vector<vector<int>>& matrix, int k) {
        if(!matrix.size()) return -1;
        int n = matrix.size(),start=matrix[0][0],end = matrix.back().back(),mid;
        while(start<end){
            mid = start+(end-start)/2;
            int count =0,j=n-1;
            for(int i=0;i<n;i++){
                while(j>=0 && matrix[i][j]>mid) {
                    j--;
                    //count++;
                }
                count += (j+1);
            }
            if(count < k ) {
                start = mid+1;
            }else
                end = mid;
        }
        return start;
    }
