
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        for(int i=0;i<tickets.size();i++){
            if(map1.count(tickets[i].first) ){
                map1[tickets[i].first].insert(tickets[i].second);
            }else{
                map1[tickets[i].first] = multiset<string>({tickets[i].second});
            }
        }
        visit("JFK");
        return vector<string>(res.rbegin(),res.rend());
    }
    unordered_map<string,multiset<string>> map1;
    vector<string> res;
        
    void visit(string str){
        
        while(map1[str].size()){
            string tmp = *(map1[str].begin());
            map1[str].erase((map1[str].begin()));
            visit(tmp);
        }
          res.push_back(str);
    }     
