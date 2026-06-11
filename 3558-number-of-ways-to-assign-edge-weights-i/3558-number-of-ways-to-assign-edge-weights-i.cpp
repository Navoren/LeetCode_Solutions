class Solution {
    const int MOD = 1e9 + 7;
public:
    int dfs(int node, int parent, vector<vector<int>> &adj){
        int depth = 0;
        for(auto it : adj[node]){
            if(it == parent) continue;
            depth = max(depth, dfs(it, node, adj)+1);
        }
        return depth;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n+1);
        for(auto &it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int depth = dfs(1 ,0, adj);

        long long ans = 1; 
        for (int i = 1; i < depth; i++) {
            ans = (ans * 2) % MOD;
        }
        return ans;
    }
};