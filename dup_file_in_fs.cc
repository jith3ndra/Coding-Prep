


    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string>> map1;
        vector<vector<string>> res;
        string path="",file="",content="";
        for(int i=0;i<paths.size();i++){
            int j=0;path="";
            while(paths[i][j]!=' '){
                path+=paths[i][j++];
            }
            path+="/";
            while(j<paths[i].size()){
                file="";content="";
                j++;
                while(paths[i][j]!='('){
                    file+=paths[i][j++];
                }
                j++;
                while(paths[i][j]!=')'){
                    content+=paths[i][j++];
                }
                j++;
                //cout << content << " "<<path+file<<endl;
                map1[content].push_back(path+file);
            }
            
        }
        for(auto i=map1.begin();i!=map1.end();++i){
            if(i->second.size()>1)
            res.push_back(i->second);
        }
        return res;
    }
