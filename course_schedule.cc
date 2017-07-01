bool canFinish(vector<vector<int>> graph,vector<int> ind){
        queue<int> stk;
        for(int i=0;i<ind.size();i++){
            if(!ind[i]){
                stk.push(i);
            }
        }
        
        if(!stk.size()) return false;
        else{
            int num;
            int ctr=0;
            while(stk.size()){
                num = stk.front();
                stk.pop();
                ctr++;
                for(int i=0;i<graph[num].size();i++){
                    ind[graph[num][i]]--;
                    if(!ind[graph[num][i]]){
                        stk.push(graph[num][i]);
                    }
                }
            }
            if(ctr==graph.size()){
                return true;
            }else
                return false;
        }
    }
    bool canFinish(int numCourses, vector<pair<int, int>>& pre) {
        vector<vector<int>> graphs(numCourses,vector<int>({}));
        vector<int> indegree(numCourses,0);
        for(int i=0;i<pre.size();i++){
            graphs[pre[i].second].push_back(pre[i].first);
            indegree[pre[i].first]++;
        }
        return canFinish(graphs,indegree);
    }
