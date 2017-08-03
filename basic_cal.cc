
    int calculate(string s) {
        if(!s.size()) return 0;
        char sign='+';
        int num=0;stack<int>stk;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                num=(num*10)+s[i]-'0';
            }
            if(!isdigit(s[i]) && s[i]!=' ' || i==s.size()-1){
                if(sign=='+'){
                    stk.push(num);
                }
                if(sign=='-'){
                    stk.push(-num);
                }
                if(sign=='*'){
                    int k= stk.top();
                    stk.pop();
                    stk.push(k*num);
                }
                if(sign=='/'){
                    int k= stk.top();
                    stk.pop();
                    stk.push(k/num);
                }
                sign = s[i];
                num=0;
            }
        }
        int res=0;
        while(stk.size()){
            res+= stk.top();
            stk.pop();
        }
        return res;
    }
