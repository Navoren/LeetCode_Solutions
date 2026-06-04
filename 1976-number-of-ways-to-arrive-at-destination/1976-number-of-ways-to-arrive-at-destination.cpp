class Solution {
    const long long MOD = 1e9 + 7;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &it : roads){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0,0}); //(time, node)
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            long long time = it.first;
            int node = it.second;
            for(auto &[adjNode, wt] : adj[node]){
                long long newTime = time + wt;
                if(newTime < dist[adjNode]){
                    dist[adjNode] = newTime;
                    ways[adjNode] = ways[node];
                    pq.push({newTime, adjNode});
                }else if(newTime == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }
        return ways[n-1];
    }
};