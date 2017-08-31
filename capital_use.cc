
bool detectCapitalUse(string word) {
        if(word.size()<=1)return true;
        bool all_small = (word[1]<='z' && word[1]>='a');
        if(word[0]<='z' && word[0]>='a' && !all_small) return false;
        for(int i=1;i<word.size();i++){
            if((!all_small && word[i]<='z' && word[i]>='a' ) || (all_small && word[i]>='A' && word[i]<='Z')){
                return false;
            }
        }
        return true;
    }
