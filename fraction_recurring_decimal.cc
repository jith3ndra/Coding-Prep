
    string fractionToDecimal(int num, int den) {
        if(num==0||den==0) return "0";
        string res="";unordered_map<int ,int> map1;
        if(num<0 ^ den<0) res+='-';
        long long num1 = llabs(num);
        long long den1= llabs(den);
        res+=to_string(num1/den1);
        if(num1%den1)res+='.';
        else return res;
        for(num1=num1%den1;num1;num1%=den1){
            if(map1.count(num1)){
                res.insert(map1[num1],1,'(');
                res+=')';
                break;
            }else{
                map1[num1] = res.size();
            }
            num1*=10;
            res+=to_string(num1/den1);
        }
        return res;
    }
