class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for(auto &it : invocations){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }
        

        vector<int> sus(n,0);
        dfs(k, adj, sus);

        for(auto& it : invocations){
            int u = it[0];
            int v = it[1];

            if(!sus[u] && sus[v]){
                vector<int> ans;
                for(int i=0; i<n;i++)
                ans.push_back(i);
                return ans;
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!sus[i]) ans.push_back(i);
        }

        return ans;
    }

    void dfs(int node, vector<vector<int>>&adj, vector<int> &sus){
        sus[node] = 1;
        for(auto &it: adj[node]){
            if(!sus[it]) dfs(it, adj, sus);
        }
    }
};
