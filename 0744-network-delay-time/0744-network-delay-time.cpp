class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n+1);
        for(auto it : times){
            int u = it[0], v = it[1], wt = it[2];
            graph[u].push_back({v,wt});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;
        pq.push({0,k});

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int u = it.second;
            int dis = it.first;

            for(auto& [v,wt] : graph[u]){
                if(dis + wt < dist[v]){
                    dist[v] = dis + wt;
                    pq.push({dist[v], v});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};
