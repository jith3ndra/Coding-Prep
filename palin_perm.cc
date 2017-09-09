

bool canPermutePalindrome(string s) {
        if(s.size()<=1) return true;
        vector<int> ary(256,0);
        bool odd= false;
        for(int i=0;i<s.size();i++){
            ary[s[i]]++;
        }
        for(int i=0;i<256;i++){
           if( !odd && ary[i]%2==1){
               odd=true;
           }else if(odd && ary[i]%2==1){
               return false;
           }
        }
        return true;
    }
