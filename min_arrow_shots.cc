

int findMinArrowShots(vector<pair<int, int>>& points) {
        if(!points.size()) return 0;
        sort(points.begin(),points.end(),[](pair<int,int>a,pair<int,int>b){return a.first<b.first || (a.first==b.first && a.second>b.second);});
        int end=points[0].second,arrows=1;
        for(int i=1;i<points.size();i++){
            if(points[i].first>end){
                end = points[i].second;
                arrows+=1;
            }else if(points[i].first<=end){
                end = min(end,points[i].second); 
            }
        }
        return arrows;
    }
