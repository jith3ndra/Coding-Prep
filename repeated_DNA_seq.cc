

vector<string> findRepeatedDnaSequences(string s) {
        if(s.size()<=9) return {};
        unordered_map<string,int> map1;
        string str;vector<string> res;
        for(int i=0;i<s.size()-9;i++){
            str = s.substr(i,10);
            if(map1[str]==1){ // allow the substr in res only if it is not present eg.;case AAAAAAAAAAAA
                res.push_back(str);
            }
            map1[str]++;
        }
        return res;
    }
