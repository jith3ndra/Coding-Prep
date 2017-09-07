
void clean(string &s){
        int j=0;
        for(int i=0;i<s.size();i++){
            if((i==0 && s[i]==' ') || (s[i]==' ' && s[i-1]==' ')|| (s[i]==' ' && i==s.size()-1)){
                continue;
            }else{
                s[j++]=s[i];
            }
        }
        s = s.substr(0,j);
        if(s[(int)s.size()-1]==' '){
            s = s.substr(0,(int)s.size()-1);
        }
    }
    int countSegments(string s) {
        clean(s);
        //cout << s<< endl;
        if(!s.size())return 0;
        return (int)count(s.begin(),s.end(),' ')+1;
        
    }
