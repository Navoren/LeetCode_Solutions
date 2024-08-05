class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mpp;
        for(auto& v : arr) ++mpp[v];
        for(auto& v : arr){
            if(mpp[v] == 1){
                --k;
                if(k == 0) return v;
            }
        }
        return "";
    }
};