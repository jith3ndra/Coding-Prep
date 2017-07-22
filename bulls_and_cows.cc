



    string getHint(string secret, string guess) {
        vector<int> nums1(10,0),nums2(10,0);
        int bulls=0,cows=0;string res="";
        for(int i=0;i<guess.size();i++){
            if(guess[i]==secret[i]){
                bulls++;
            }else{
                nums1[(secret[i])-'0']++;
                nums2[(guess[i])-'0']++;
            }
        }
        for(int i=0;i<10;i++){
            cows+= min(nums1[i],nums2[i]);
        }
            res+=to_string(bulls) +"A";
            res+=to_string(cows)+"B";
        return res;
        
    }
