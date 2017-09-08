
int shortestDistance(vector<string>& words, string word1, string word2) {
        int dist =INT_MAX,d1=-1,d2=-1;
        for(int i=0;i<words.size();i++){
            if(words[i]==word1){
                d1 = i;
            }
            if(words[i]==word2){
                d2 = i;
            }
            if(d1!=-1 && d2!=-1){
                dist = min(dist,abs(d1-d2));
            }
        }
        return dist;
    }
