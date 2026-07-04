class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &it : roads){
            int u = it[0];
            int v = it[1];
            int dist = it[2];
            adj[u].push_back({v, dist});
            adj[v].push_back({u, dist});
        }

        vector<int> vis(n+1, 0);
        int ans = INT_MAX;
        dfs(1, adj, vis, ans);
        return ans;
    }

    void dfs(int node,vector<vector<pair<int,int>>> &adj, vector<int> &vis, int &ans){
        vis[node] = 1;

        for(auto &it : adj[node]){
            int adjNode = it.first;
            int dis = it.second;

            ans = min(ans, dis);

            if(!vis[adjNode]){
                dfs(adjNode, adj, vis, ans);
            }
        }
    }
};