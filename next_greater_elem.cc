


    int nextGreaterElement(int n) {
        if(n<10) return -1;
        string str = to_string(n);
        char temp;int k=-1,res=0;
        for(int i=str.size()-1;i>0;i--){
            if(str[i] > str[i-1]){
                k=i;temp = str[i-1];
                break;
            }
        }
        if(k==-1) return -1;
        for(int i=str.size()-1;i>=k;i--){
            if(temp<str[i]){
                swap(str[k-1],str[i]);
                break;
            }
        }
        reverse(str.begin()+k,str.end());
        //cout << str <<endl;
        k=0;
        while(k<str.size()){
            if( (res == INT_MAX/10 && str[k]-'0' > INT_MAX%10) || res > INT_MAX/10 ){
                return -1;
            }
            res*=10;
            res +=str[k]-'0';
            k++;
        }
        return stoi(str);
    }
