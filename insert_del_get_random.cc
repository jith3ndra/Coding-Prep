class RandomizedSet {
    unordered_map<int,int> map1;
    vector<int> res;
    int  size = 0;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(!map1.count(val)){
            map1[val] = size++;
            res.push_back(val);
            return true;
        }
            return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(!map1.count(val)) return false;
        int temp = res.back();
        map1[temp]= map1[val];
        res[map1[val]]=temp;
        res.pop_back();
        size--;
        map1.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if(!size) return -1;
        int ind = rand()%(size);
        return res[ind];
    }
};
