

 void nextPermutation(vector<int>& nums) {
        int size = nums.size(),temp, m = size-1,i= size-1;
        if(size==1|| !size) return ;
        // the idea is to find an elem suchthat it is greater than the its predecessor starting from the last elementof the array. //[6 8 7 4 3 2]  eg. find index of 8  (8>6).
        // find the smallest number whichis larger than 6. here it is 7 swap them 
        //[7 8 6 4 3 2] 
        // now reverse all the elems after 7 
        //[7 2 3 4 6 8]
        
        while(i && nums[i-1] >=nums[i]){
            i--;
        }
        if(i>0){
            for(int j=size-1;j>=i;j--){
                 if(nums[j] > nums[i-1]){
                    temp = nums[j];
                    nums[j] = nums[i-1];
                    nums[i-1] = temp;
                    break;
                }
            }
        }
        while(i<m){
            temp = nums[i];
            nums[i] = nums[m];
            nums[m] = temp;
            i++;m--;
        }
        return;
    }
