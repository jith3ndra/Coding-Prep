


    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0") return "0";
        vector<int> res(num1.size()+num2.size(),0);
        for(int i=num1.size()-1;i>=0;i--){
            for(int j=num2.size()-1;j>=0;j--){
                int p1 = i+j,p2= i+j+1;
                int mul = (num1[i]-'0') * (num2[j]-'0');
                int sum = mul + res[p2];
                res[p1] += sum/10;
                res[p2] = sum%10;
            }
        }
        string ans="";
        for(int i=0;i<res.size();i++){
            if(!i && res[i]==0){
                continue;
            }
            ans += to_string(res[i]);
        }
        return ans;
    }
