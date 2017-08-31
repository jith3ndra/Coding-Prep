

int firstUniqChar(string s) {
        int res =-1;
        unordered_map<char,int> map1;
        for(int i=0;i<s.size();i++){
                map1[s[i]]++;
        }
        for(int i=0;i<s.size();i++){
            if(map1[s[i]]==1)
                return i;
        }
        return res;
    }
