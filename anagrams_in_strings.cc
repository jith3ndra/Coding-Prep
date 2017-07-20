


    vector<int> findAnagrams(string s, string p) {
        if(!s.size() || !p.size() || p.size()>s.size()) return {};
        vector<int> res;int start=0;
        vector<int> pat(256,0),str(256,0);
        for(int i=0;i<p.size();i++){
            pat[p[i]]++;
            str[s[i]]++;
        }
        //here the vector comparision is done in O(256) which is const time
        if(pat == str) res.push_back(0);
        for(int i=1;i<=s.size()-p.size();i++){
            str[s[start++]]--;
            str[s[i+p.size()-1]]++;
            if(str == pat) res.push_back(start);
        }
        return res;
    }
