class Solution {
public:
    bool check(int limit, vector<vector<pair<int,int>>> &adj, vector<bool>&online, long long k){
        int n = online.size();
        vector<long long> dist(n, 1e18);

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        >pq;

        dist[0] = 0;
        pq.push({0,0});

        while(!pq.empty()){
            long long dis = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if(dis > dist[u]) continue;
            if(u != 0 && u != n-1 && online[u] == false) continue;

            for(auto it : adj[u]){
                int v = it.first;
                int wt = it.second;

                if(wt < limit) continue;
                if(v != n-1 && online[v] == false) continue;

                if(dist[v] > dist[u] + wt){
                    dist[v] = dist[u] + wt;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist[n-1] <= k;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int,int>>> adj(n);
        int maxCost = 0;

        for(auto &it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
            maxCost = max(maxCost, wt);
        }

        if(!check(0, adj, online, k)) return -1;

        int lo = 0, hi = maxCost;
        while(lo < hi){
            int mid = lo + (hi - lo + 1)/2;

            if(check(mid, adj, online, k)) lo = mid;
            else hi = mid - 1;
        }
        return lo;
    }
};