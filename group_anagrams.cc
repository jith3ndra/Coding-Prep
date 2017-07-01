 vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map1;
        string str ="";vector<vector<string>> res;
        for(int i=0;i<strs.size();i++){
            str = strs[i];
            sort(str.begin(),str.end());
            if(map1.count(str)){
                map1[str].push_back(strs[i]);
            }else{
                map1[str]={strs[i]};
            }
        }
        for(auto i=map1.begin();i!=map1.end();++i){
            res.push_back(i->second);
        }
        return res;
    }
