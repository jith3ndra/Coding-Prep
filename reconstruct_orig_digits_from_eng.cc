



    string originalDigits(string s) {
        string res="";
        vector<int> res1(26,0),count(10,0);
        for(int i=0;i<s.size();i++){
            res1[s[i]-'a']++;
        }
        count[0] = res1['z'-'a'];
        count[2] = res1['w'-'a'];
        count[4] = res1['u'-'a'];
        count[6] = res1['x'-'a'];
        count[8] = res1['g'-'a'];
        count[7] = res1['s'-'a']-count[6];
        count[5] = res1['f'-'a']-count[4];
        count[3] = res1['h'-'a']-count[8];
        count[1] = res1['o'-'a']-count[0]-count[4]-count[2];
        count[9] = res1['i'-'a']-count[5]-count[8]-count[6];
        for(int i=0;i<count.size();i++){
            while(count[i]){
                res+=to_string(i);
                count[i]--;
            }
        }
        return res;
    }
