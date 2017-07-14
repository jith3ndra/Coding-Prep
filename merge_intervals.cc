
 vector<Interval> merge(vector<Interval>& intervals) {
        if(!intervals.size()) return {};
        vector<Interval> res;
        sort(intervals.begin(),intervals.end(),[](Interval a,Interval b){return a.start < b.start;});
        res.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){ 
            if( res.back().end < intervals[i].start){
                res.push_back(intervals[i]);
            }else{
                res.back().end = max(res.back().end,intervals[i].end);
            }
        }
        return res;
    }
