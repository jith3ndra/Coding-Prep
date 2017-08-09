


    int findPoisonedDuration(vector<int>& ts, int duration) {
        if(!duration || !ts.size()) return 0;
        int res=ts.size()*duration;
        for(int i=1;i<ts.size();i++){
            if(ts[i]-ts[i-1] < duration){
                res-= (duration-ts[i]+ts[i-1]);
            }
        }
        return res;
    }
