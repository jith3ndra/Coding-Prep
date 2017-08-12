    int gcd(int a,int b){
        while(1){
            if(b==0) return a;
                a%=b;
            if(a==0) return b;
                b%=a;
        }
    }
    int lcm1(int a,int b){
        return a*b/gcd(a,b);
    }
    int lcm_val(vector<int> num){
        if(num.size()==1)return num[0];
        else{
            int lcm = num[0];
            for(int i=1;i<num.size();i++){
                lcm = lcm1(lcm,num[i]);
            }
            return lcm;
        }
    }
    void compute_val(vector<int> nume,vector<int> den,int &numer,int &denom1){
        denom1 = lcm_val(den);
        numer=0;
        for(int i=0;i<nume.size();i++){
            numer+= (nume[i]*denom1/den[i]);
        }
        int k = gcd(denom1,abs(numer));
        numer = numer/k;
        denom1 = denom1/k;
    }
    string fractionAddition(string exp) {
        if(exp.size()==0) return "";
        vector<int> num,den;
        int i=0;bool sign=true;
        int numer1,denom1;
        if(exp[0]=='-') {
            sign =false;
            i++;
        }
        while(i<exp.size()){
            int num1=0;
            while(exp[i]!='/' ){
                num1 = num1*10+(exp[i]-'0');
                i++;
            }
            if(sign)
                num.push_back(num1);
            else
                num.push_back(-1*num1);
            i++;
            num1=0;
            while(i<exp.size() && exp[i]!='+' && exp[i]!='-'){
                num1 = num1*10+(exp[i]-'0');
                i++;
            }
            if(exp[i]=='+') sign=true;
            else sign= false;
            i++;
            den.push_back(num1);
        }
        compute_val(num,den,numer1,denom1);
        return to_string(numer1)+"/"+to_string(denom1);
    }
