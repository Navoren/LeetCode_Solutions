class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> mpp;
        for(int i = 0; i<s.length(); i++){
            mpp[s[i]]++;
        }
        int maxOdd = INT_MIN;
        int minEven = INT_MAX;

        vector<int> freq;
        for(const auto& it : mpp){
            freq.push_back(it.second);
        }

        for(int it : freq){
            if(it % 2 == 0){
                if(it < minEven){
                    minEven = it;
                }
            }else{
                if(it > maxOdd){
                    maxOdd = it;
                }
            }
        }

        if(maxOdd == INT_MIN || minEven == INT_MAX) return 0;
        return maxOdd - minEven;

    }
};