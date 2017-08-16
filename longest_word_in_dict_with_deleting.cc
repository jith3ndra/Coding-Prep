


string findLongestWord(string s, vector<string>& d) {
        string res="";
        for(int i=0;i<d.size();i++){
            if(pattern(s,d[i]) && (d[i].size()>res.size() || d[i].size()==res.size() && res > d[i])){
                res =  d[i];
            }
        }
        return res;
    }
