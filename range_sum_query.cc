vector<int> ary;
    int size =0;
    void build_seg_tree(vector<int> &ary,vector<int> nums,int start,int end,int cur){
        if(start==end){
            ary[cur] = nums[start];
        }else{
            int mid = (start+end)/2;
            build_seg_tree(ary,nums,start,mid,cur*2+1);
            build_seg_tree(ary,nums,mid+1,end,cur*2+2);
            ary[cur] = ary[cur*2+1]+ary[cur*2+2];
        }
    }
    int sum_val(vector<int> &ary,int i,int j , int start,int end,int cur){
        if(start>j || end<i){
            return 0;
        }else if(start>=i && end<=j){
            return ary[cur];
        }else{
            int m  = (start+end) /2;
            return sum_val(ary,i,j,start,m,cur*2+1)+sum_val(ary,i,j,m+1,end,cur*2+2);
        }
    }
    void update(vector<int> &ary,int i,int start,int end,int diff,int cur){
        //cout << start<< " "<<end<<endl;
        if(start<=end && start<=i && end>=i){
            ary[cur]+=diff;
            if(start==i && end==i) return ;
            int mid = (start+end)/2;
            update(ary,i,start,mid,diff,cur*2+1);
            update(ary,i,mid+1,end,diff,cur*2+2);
        }
    }
public:
    NumArray(vector<int> nums) {
        int n = nums.size();
        for(int i=0;i<2*n-1;i++){
           ary.push_back(0);
        }
        if(n)
            build_seg_tree(ary,nums,0,nums.size()-1,0);
        size = n;
    }
    
    void update(int i, int val) {
        if(size){
            int diff = val - sumRange(i,i);
            update(ary,i,0,size-1,diff,0);
        }
    }
    
    int sumRange(int i, int j) {
        if(!size) return 0;
        return sum_val(ary,i,j,0,size-1,0);
    }
