class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> inDegree(n, 0);
        vector<vector<int>> adj_reverse(n);

        // Reverse the graph and calculate inDegree
        for (int i = 0; i < n; i++) {
            for (auto it : graph[i]) {
                adj_reverse[it].push_back(i);  // Reverse the edges
                inDegree[i]++;  // Count incoming edges
            }
        }

        queue<int> q;
        vector<int> safeNodes;

        // Nodes with 0 inDegree are terminal nodes (safe)
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);  // Collect safe node

            for (auto it : adj_reverse[node]) {
                inDegree[it]--;  // Reduce inDegree
                if (inDegree[it] == 0) q.push(it);
            }
        }

        // Return the sorted list of safe nodes
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};