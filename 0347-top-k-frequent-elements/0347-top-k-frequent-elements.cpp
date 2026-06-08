class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<
            pair<int, int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq; // (freq, element)

        unordered_map<int,int> freq;
        for(auto &it : nums){
            freq[it]++;
        }
        
        for (auto it : freq) {
            int num = it.first;
            int f = it.second;

            pq.push({f, num});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> ans;
        while(!pq.empty()){
            auto ele = pq.top();
            ans.push_back(ele.second);
            pq.pop();
        }

        return ans;
    }
};