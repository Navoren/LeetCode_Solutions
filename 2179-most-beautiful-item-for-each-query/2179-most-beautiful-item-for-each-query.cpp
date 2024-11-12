class Solution {
public:
    bool isPossible(const vector<vector<int>>& items, int idx, int priceLimit) {
        return items[idx][0] <= priceLimit;
    }

    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        
        int n = items.size();
        vector<int> maxBeauty(n);
        maxBeauty[0] = items[0][1];
        
        for (int i = 1; i < n; ++i) {
            maxBeauty[i] = max(maxBeauty[i - 1], items[i][1]);
        }

        vector<int> result;
        for (const auto& query : queries) {
            int left = 0, right = n - 1, bestIdx = -1;
            
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (isPossible(items, mid, query)) {
                    bestIdx = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }

            if (bestIdx != -1) {
                result.push_back(maxBeauty[bestIdx]);
            } else {
                result.push_back(0);
            }
        }

        return result;
    }
};
