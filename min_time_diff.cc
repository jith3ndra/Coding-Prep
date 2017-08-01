


int diff (string a,string b){
        int t1 = stoi(a.substr(0,2))*60 + stoi(a.substr(3,2));
        int t2 = stoi(b.substr(0,2))*60 + stoi(b.substr(3,2));
        return min(abs(t1-t2),1440 - abs(t1-t2));
    }
    int findMinDifference(vector<string>& tp) {
        
        sort(tp.begin(),tp.end(),[](string a,string b){return a[0]<b[0] ||( a[0]==b[0] && a[1]<b[1] ) || (a[0]==b[0] && a[1]==b[1] && a[3]<b[3]) || (a[0]==b[0] && a[1]==b[1] && a[3]==b[3] && a[4]<b[4]);});
        int min1=INT_MAX;
        int size = tp.size();
        for( int i=0;i<size;i++){
            min1 = min(min1,diff(tp[i%size],tp[(i+1)%size]));
        }
        return min1;
    }
