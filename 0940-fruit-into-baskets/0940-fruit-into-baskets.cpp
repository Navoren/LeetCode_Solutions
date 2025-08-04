class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int,int> mpp;
        int left = 0;
        int maxFruits = 0;

        for(int right =0; right<n; right++){
            mpp[fruits[right]]++;

            while(mpp.size() > 2){
                mpp[fruits[left]]--;
                if(mpp[fruits[left]] == 0){
                    mpp.erase(fruits[left]);
                }
                left++;
            }
            maxFruits = max(maxFruits, right-left+1);
        }
        return maxFruits;
    }
};