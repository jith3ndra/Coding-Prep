


    bool is_subseq(string s1,string s2){
        int i=0,j=0;
        while(i<s1.size() && j<s2.size()){
            if(s1[i]==s2[j]){
                i++;j++;
            }else{
                j++;
            }
        }
        if(i==s1.size()) return true;
        return false;
    }
    int findLUSlength(vector<string>& strs) {
        unordered_map<string,int> map1;
        int res=-1;vector<string> str;bool flag;
        for(int i=0;i<strs.size();i++){
            if(map1[strs[i]]++==0){
                str.push_back(strs[i]);
            }    
        }
        //cout << "##"<<endl;
        sort(str.begin(),str.end(),[](string a,string b){return a.size()<b.size();});
        for(int i=str.size()-1;i>=0;i--){
            flag = true;
            if(map1[str[i]]==1){
                for (int j=i+1;j<str.size();j++){
                    if(is_subseq(str[i],str[j])){
                        flag = false;
                        break;
                    }
                }
                if(flag) return str[i].size();
            }
        }
        return res;
    }
