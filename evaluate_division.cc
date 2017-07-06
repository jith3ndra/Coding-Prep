public:
    double cost(string str1,unordered_map<string,vector<pair<string,double>>> graph){
        //cout << str << endl;
        double res = 1;
        vector<string> str;
        stringstream ss(str1); // Turn the string into a stream.
          string tok;
  
        while(getline(ss, tok, '*')) {
         str.push_back(tok);
        }
        
#if 1//0        
        for(int i=0;i<str.size()-1;i++){
            //cout << "##*"<<endl;
            
            for(auto j=graph[str[i]].begin();j!=graph[str[i]].end();++j){
                //cout << "**"<<endl;
                if(j->first == str[i+1]){
                    //cout << j->second <<endl;
                    res *= j->second;
                    break;
                }
            }
        }
#endif        
        return res;
    }
    map<string,int>visited;
    
    string find_path(string src, string dst, unordered_map<string,vector<pair<string,double>>> graph){
        if(src == dst){
            return src+"*"+dst;
        }
        string path = "";
        if(!graph.count(src) || !graph.count(dst)){
            return "";
        }else{
            string str ;
            visited[src] =1;
            for(int i=0;i<graph[src].size();i++){
               // cout <<  graph[src][i].first << endl;
                if(graph[src][i].first == src || visited[graph[src][i].first]==1) continue;
                str ="";
                if(graph[src][i].first != dst)
                    str = find_path(graph[src][i].first,dst,graph);
                if(str.size() || graph[src][i].first == dst){
                     path = src + "*"+graph[src][i].first+"*"+str;
                    break;
                }
            }
            visited[src] = 0;
            return path;
        }    
    }  
    
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        vector<double> res;
        if(!equations.size() || !values.size() || !queries.size()){
            return res;
        }else{
            unordered_map<string,vector<pair<string,double>>> graph;
            for(int i=0;i<equations.size();i++ ){
                //cout << (double)1.0/values[i] <<endl;
                graph[equations[i].first].push_back(make_pair(equations[i].second,values[i]));
                graph[equations[i].second].push_back(make_pair(equations[i].first,1.0/values[i]));
            }
            for(auto i= graph.begin();i!=graph.end();++i){
                graph[i->first].push_back(make_pair(i->first,1.0));
                visited[i->first] = 0;
            }
            for(int i=0;i<queries.size();i++){
                
                if(!graph.count(queries[i].first) && !graph.count(queries[i].second)){
                    res.push_back(-1.0);
                }else{
                    if(queries[i].first== queries[i].second){
                        res.push_back(1.0);
                        continue;
                    }
                    string path;
                    path = find_path(queries[i].first,queries[i].second,graph);
                    if(!path.size()){
                        res.push_back(-1.0);
                    }else
                        res.push_back(cost(path,graph));
                }
            }
            return res;
        }
        
    }
};
