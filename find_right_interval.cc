


    vector<int> findRightInterval(vector<Interval>& intervals) {
        
        vector<int> res(intervals.size(),-1);
        map<int,int> map1;
        for( int i=0;i<intervals.size();i++){
            map1[intervals[i].start] = i;
        }
        for(int i=0;i<intervals.size();i++){
           auto k = map1.lower_bound(intervals[i].end);
            if(k!=map1.end())
            res[i] = k->second;
        }
        return res;
    }
