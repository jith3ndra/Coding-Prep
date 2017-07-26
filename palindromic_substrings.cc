

int palin (string s, int i,int j){
        int cnt=0;
        while(i>=0 && j<s.size()){
            if(s[i]==s[j]){
                cnt++;
                i--;j++;
            }else
                break;
        }
        return cnt;
    }
public:
    int countSubstrings(string s) {
        int res =0;
        if(!s.size()) return 0;
        for(int i=0;i<s.size();i++){
            res+= palin(s,i,i);
            res+= palin(s,i,i+1);
        }
        return res;
    }
