class MyHashSet {
private:
    int n = 10000;
    vector<vector<int>> arr;    
public:
    MyHashSet() {
        arr.resize(n);
    }
    
    void add(int key) {
        int ind = key%n;
        for(int x : arr[ind]){
            if(x == key) return;
        }
        arr[ind].push_back(key);
    }
    
    void remove(int key) {
        int ind = key%n;
        for(int i = 0; i< arr[ind].size(); i++){
            if(arr[ind][i] == key){
                arr[ind].erase(arr[ind].begin() + i);
                return;
            }
        }
    }
    
    bool contains(int key) {
        int ind = key%n;
        for(int x : arr[ind]){
            if(x == key) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */