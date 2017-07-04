    vector<int> findOrder(vector<int> ind,vector<vector<int>> graph ){
        queue<int> stk;
        for(int i=0;i<ind.size();i++){
            if(!ind[i]){
                //cout << i << endl;
                stk.push(i);
            }
        }
        if(!stk.size()){
            return {};
        }
        vector<int> res;
        
        while(stk.size()){
            //cout << stk.front()<<endl;
            res.push_back(stk.front());
            stk.pop();
            for(int i=0;i<graph[res.back()].size();i++){
                ind[graph[res.back()][i]]--;
                if(!ind[graph[res.back()][i]]){
                    stk.push(graph[res.back()][i]);
                }
            }
        }
        if(res.size()!=graph.size()){
            return {};
        }else
            return res;
    }
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& pre) {
        vector<vector<int>> graph(numCourses,vector<int>({}));
        vector<int> ind(numCourses,0);
        for(int i=0;i<pre.size();i++){
            graph[pre[i].second].push_back(pre[i].first);
            ind[pre[i].first]++;
        }
        return findOrder(ind,graph);
    }
