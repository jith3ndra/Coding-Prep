

int myAtoi(string str) {
        if(!str.size()) return 0;
        int i=0,sign=1,res=0;
        while(str[i]==' ') i++;
        str = str.substr(i);
        i=0;
        if(str[i]=='-') {sign=-1;i++;str=str.substr(1);}
        else if(str[i]=='+'){i++;str=str.substr(1);}
        while(str[i]>='0' && str[i]<='9')i++;
        str = str.substr(0,i);
        i=0;
        while(i<str.size()){
            if(!isdigit(str[i])){
                return 0;
            }
            if(sign==1 && (res>INT_MAX/10 || (res==INT_MAX/10 && str[i]-'0'>INT_MAX%10))){
                return INT_MAX;
            }
            if(sign==-1 && ((res>INT_MAX/10) || (res==INT_MAX/10 && str[i]-'0'>(INT_MAX%10+1)) )){
                return INT_MIN;
            }
            res = res*10+(str[i]-'0');
            i++;
        }
        return sign*res;
    }
