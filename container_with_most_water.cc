int maxArea(vector<int>& height) {
        int res =0,temp = 0;
        int left = 0,right = height.size()-1;
        
        while(left < right ){
            res = max(res,min(height[left],height[right])*(right-left));
            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }
        }
        return res;
    }
