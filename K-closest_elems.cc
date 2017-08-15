

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int start = 0,end= arr.size()-1,mid;
        vector<int> res;
        while(start<=end){
            mid = (start+end)/2;
            if(arr[mid]==x || (mid==0 && arr[mid]>x ) || (mid==arr.size()-1 && x>arr[mid])|| (x >arr[mid] && arr[mid+1]>x)){
                break;
            }else if(arr[mid] > x){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        
        if(mid==0){
            for(int i=0;i<k;i++){
                res.push_back(arr[i]);
            }
        }else if(mid==arr.size()-1){
            for(int i=mid;i>mid-k;i--){
                res.push_back(arr[i]);
            }
            reverse(res.begin(),res.end());
        }else{
            int i=mid,j=mid+1;
            for(;k && (i>=0 || j<=arr.size()-1);){
                if(i>=0 && j<=arr.size()-1 && abs(arr[i]-x) <=abs(arr[j]-x)){
                    i--;
                }else if(i>=0 && j<=arr.size()-1 && abs(arr[i]-x)> abs(arr[j]-x)){
                    j++;
                }else if(i>=0 ){
                    i--;
                }else{
                    j++;
                }
                k--;
            }
            for(int k1=i+1;k1<=j-1;k1++)
            res.push_back(arr[k1]);
            //sort(res.begin(),res.end());
        }
        return res;
    }
