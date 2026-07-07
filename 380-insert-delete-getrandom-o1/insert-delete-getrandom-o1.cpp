class RandomizedSet {
public:
    unordered_map<int, int> mp;
    vector<int> v;
    RandomizedSet() {
        
    }

    bool search (int val) {
        if (mp.find(val) != mp.end())
            return true; // present
        return false;
    }
    bool insert(int val) {
        if (search(val))
            return false;
        v.push_back(val);
        mp[val] = v.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (search(val)) {
            // find current element's index
            int idx = mp[val];
            // swap with last element
            int last = v.back();
            v[idx] = last;
            mp[last] = idx;
            // now assume the last element is at the end, pop_back
            v.pop_back();
            mp.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */