class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> graph(n);
        for (auto& it : edges) {
            int u = it[0], v = it[1], wt = it[2];
            graph[u].push_back({v, wt});
            graph[v].push_back({u, wt});
        }

        int result = -1;
        int minReach = n;

        for (int i = 0; i < n; i++) {
            vector<int> dist(n, INT_MAX);
            dist[i] = 0;

            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
            pq.push({0, i});

            while (!pq.empty()) {
                auto it = pq.top();
                pq.pop();
                int dis = it.first;
                int u = it.second;

                for (auto& [v, wt] : graph[u]) {
                    if (dist[u] + wt < dist[v]) {
                        dist[v] = dist[u] + wt;
                        pq.push({dist[v], v});
                    }
                }
            }

            int reachable = 0;
            for (int j = 0; j < n; j++) {
                if (dist[j] <= distanceThreshold) {
                    reachable++;
                }
            }
            if (reachable <= minReach) {
                minReach = reachable;
                result = i;
            }
        }

        return result;
    }
};
