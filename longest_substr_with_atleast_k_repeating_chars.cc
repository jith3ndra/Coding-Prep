

  int longestSubstring(string s, int k) {
        if(k>s.size() || s.size()==0) return 0;
        vector<int> ary(26,0);
        for(int i=0;i<s.size();i++){
            ary[s[i]-'a']++;
        }
        int i=0;
        while(i<s.size() && ary[s[i]-'a']>=k){
            i++;
        }
        if(i==s.size()) return s.size();
        return max(longestSubstring(s.substr(0,i),k),longestSubstring(s.substr(i+1),k));
    }
