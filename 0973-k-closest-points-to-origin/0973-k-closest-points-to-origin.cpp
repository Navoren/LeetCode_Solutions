class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<int> dist;
        for(auto it : points){
            int x = it[0];
            int y = it[1];
            dist.push_back((x*x + y*y));
        }

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        >pq;
        for(int i=0; i< dist.size(); i++){
            pq.push({dist[i], i});
        }

        vector<vector<int>> ans;
        while(k > 0){
            auto idx = pq.top().second;
            pq.pop();
            ans.push_back({points[idx][0], points[idx][1]});
            k--;
        }
        return ans;
    }
};