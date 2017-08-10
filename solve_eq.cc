



    void extract(string str,int &rx,int &rc){
        int x = 0,c = 0,i=0;
        bool sign = true;
        while( i<str.size() ){
            int num =0;
            while(i<str.size() && str[i]!='-' && str[i]!='+') {
                if(str[i]=='x'){
                    if(i!=0 && str[i-1]=='0'){
                        num=0;
                    }else if(num==0)
                        num=1;
                    if(sign)
                        x += num;
                    else
                        x -= num;
                }else
                    num = num*10 + str[i]-'0';
                i++;
            }
            if(i==0 || i>=1 && str[i-1]!='x'){
                if(sign)
                c += num;
                else
                c -= num;
            }
            if(str[i]=='-') sign = false;
            else sign = true;
            i++;
        }
        rx= x;
        rc= c;
    }
    string solveEquation(string equation) {
        if(!equation.size()) return "No solution";
        int lx=0,rx=0,lc=0,rc=0,i=0;
        while(equation[i]!='='){
            i++;
        }
        string lhs = equation.substr(0,i);
        i++;
        string rhs = equation.substr(i);
        extract(lhs,lx,lc);
        extract(rhs,rx,rc);
        if(lx==rx && lc==rc) return "Infinite solutions";
        if(lx==rx && lc!=rc) return "No solution";
        return "x="+to_string((rc-lc)/(lx-rx));
    }
