string toHex(int num) {
        string res="";int count=0;
        if(!num) return "0";
        vector<char> map1 = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        while(num && count++<8 ){
            res= map1[num&15]+res;
            num = (num >> 4);
        }
        return res;
    }
