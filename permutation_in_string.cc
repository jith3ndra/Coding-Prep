


    bool checkInclusion(string s1, string s2) {
        vector<int> str1(26,0),str2(26,0);
        if(s1.size()>s2.size())return false;
        for(int i=0;i<s1.size();i++){
            str1[s1[i]-'a']++;
            str1[s2[i]-'a']--;
        }
        if(str1==str2){
            return true;
        }
        for(int i=s1.size();i<s2.size();i++){
            str1[s2[i]-'a']--;
            str1[s2[i-(int)s1.size()]-'a']++;
            if(str1==str2){
                return true;
            }
        }
        return false;
    }
