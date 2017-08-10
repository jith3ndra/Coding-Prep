int dist(vector<int> p1,vector<int>p2){
        return pow(p1[0]-p2[0],2)+pow(p1[1]-p2[1],2);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_set<int> set1;
        if(p1==p2 || p1==p3 || p1==p4 ||p2==p3|| p2==p4 || p3==p4) return false;
        set1.insert(dist(p1,p2));
        set1.insert(dist(p1,p3));
        set1.insert(dist(p1,p4));
        set1.insert(dist(p2,p3));
        set1.insert(dist(p2,p4));
        set1.insert(dist(p3,p4));
        if(set1.size()!=2) return false;
        return true;
    }
