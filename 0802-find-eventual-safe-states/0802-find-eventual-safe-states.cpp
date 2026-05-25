class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj_rev(n);

        vector<int> outdegree(n, 0);
        for(int u = 0; u < n; u++){
            for(int v : graph[u]){
                adj_rev[v].push_back(u);
                outdegree[u]++;
            }
        }
        queue<int> q;
        for(int i=0; i<n; i++){
            if(outdegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> states;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            states.push_back(node);
            for(auto it : adj_rev[node]){
                outdegree[it]--;
                if(outdegree[it] == 0) q.push(it);
            }
        }

        sort(states.begin(), states.end());
        return states;
    }
};