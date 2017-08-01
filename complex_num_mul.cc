


    string complexNumberMultiply(string a, string b) {
        int a1,a2,b1,b2,i=0;
        string res ="";
        if(a.size() && b.size()){
            a1 = stoi(a.substr(0,a.find('+')));
            b1 = stoi(a.substr(a.find('+')+1,a.find('i')-a.find('+')-1));
            a2 = stoi(b.substr(0,b.find('+')));
            b2 = stoi(b.substr(b.find('+')+1,b.find('i')-b.find('+')-1));
            res = to_string(a1*a2-b1*b2)+"+"+to_string(a1*b2+b1*a2)+"i";
        }
        return res;
    }
