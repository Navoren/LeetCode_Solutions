class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &it: flights){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
        }

        queue<
        pair<int, pair<int,int>>
        >q;

        q.push({0, {src, 0}});
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        while(!q.empty()){
            int stop = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();
            if(stop > k) continue;
            for(auto &[v, wt] : adj[node]){
                if(wt + cost < dist[v] && stop <= k){
                    dist[v] = wt + cost;
                    q.push({stop +1, {v, dist[v]}});
                }
            }
        }


        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }
};