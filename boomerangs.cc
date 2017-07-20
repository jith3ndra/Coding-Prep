

int numberOfBoomerangs(vector<pair<int, int>>& points) {
        if(!points.size()) return 0;
        float dist;int bom=0;
        for(int i=0;i<points.size();i++){
            
        unordered_map<int,int> map1;
            for(int j=0;j<points.size();j++){
                if(i==j)continue;
                map1[pow(points[j].first - points[i].first, 2) + pow(points[j].second - points[i].second, 2)]++;
            }
            for (auto& p : map1) 
                bom += p.second * (p.second - 1);
        }
        return bom;
}
