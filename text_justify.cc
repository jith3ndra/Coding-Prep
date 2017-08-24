


    // first how many words can be fit in a line. how many spaces we need for that line.
    // spread those spaces evenly. need to decide how many spaces should be there after each word.
    // last line should be left justified.
    string justify(vector<string> words, int start,int end,int spaces){
        string res="",temp;int rem;
        if(end-start-1!=0)
            rem = spaces%(end-start-1);
        if(start+1==end) {
            temp="";
            temp+=words[start];
            while(spaces-->0)
            temp+=' ';
            return temp;
        }
        for(int i=start;i<end;i++){
            temp="";
            if(i!=end-1){
                temp+=words[i]+ " ";
                int ctr= spaces/(end-start-1);
                while(ctr>0){
                    temp+= " ";
                    ctr--;
                }
                if(rem){
                    temp+=" ";
                    rem--;
                }
            }else
                temp+=words[i];
            res += temp;
        }
        return res;
    }
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        if(!words.size()) return {""};
        int i=0,j=0;int temp;vector<string>res;
        while(i<words.size()){
            temp = maxWidth;
            j=i;
            while(i<words.size() && temp>=(int)words[i].size()){
                temp-= (words[i].size()+1);
                i++;    
            }
            if(i!=words.size())
                res.push_back(justify(words,j,i,temp+1));
            else{
                string tmp="";
                for(int k=j;k<i;k++){
                    if(k!=i-1)
                        tmp+=(words[k]+" ");
                    else
                        tmp+= words[k];
                }
                while(tmp.size()<maxWidth){
                    tmp+=' ';
                }
                res.push_back(tmp);
            }
                
        }
            return res;
    }
