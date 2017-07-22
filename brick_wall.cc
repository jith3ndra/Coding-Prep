


int leastBricks(vector<vector<int>>& wall) {
        if(!wall.size()) return 0;
        unordered_map<int,int> map1;
        int ctr,max1=0;
        for(int i=0;i<wall.size();i++){
             ctr=0;
            for(int j=0;j<wall[i].size()-1;j++){   
                ctr+=wall[i][j];
                if(map1.count(ctr))
                    map1[ctr]++;
                else
                    map1[ctr]=1;
            }
        }
        
        for( auto i=map1.begin();i!=map1.end();++i){
            max1 = max(max1,i->second);
        }
        return (int)wall.size() - max1;
    }
