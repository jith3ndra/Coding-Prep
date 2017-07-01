int trap(vector<int>& height) {
        int res =0,temp = 0;
        vector<int> right(height.size(),0);
        for(int i=height.size()-2;i>=0;i--){
            right[i] = max(right[i+1],height[i+1]);
        }
        int left = 0,water;
        for(int i=1;i<height.size();i++){
            left = max(left,height[i-1]);
            res+= (min(left,right[i]) - height[i])>0?min(left,right[i]) - height[i]:0;
        }
        return res;
    }
