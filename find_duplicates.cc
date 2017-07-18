

  vector<string> findWords(vector<string>& words) {
        if(words.size()<=1) return words;
        unordered_map<char,int> map1;
        vector<string> res;
        vector<string> str = {"qwerttyuiop","asdfghjkl","zxcvbnm"};
        for(int i=0;i<str.size();i++){
            for(int j=0;j<str[i].size();j++){
                map1[str[i][j]] = i;
            }
        }
        bool flag ;char x,y;
        for(int j=0;j<words.size();j++){
            flag = true;
        for(int i=1;i<words[j].size();i++){
            x = map1.count(words[j][i]) ? words[j][i]:tolower(words[j][i]); 
            y = map1.count(words[j][i-1]) ? words[j][i-1]:tolower(words[j][i-1]); 
                if(i && map1[x] != map1[y]){
                    flag = false;
                     break;
                }
  
        }
            if(flag) res.push_back(words[j]);
        }
        return res;
    }
