class Solution {
public:
char dfs(unordered_map<char, vector<char>>& adj, char curr, vector<int>& vis){
    vis[curr - 'a'] = 1;
    char minChar = curr;
    for(char neighbor : adj[curr]){
        if(vis[neighbor - 'a'] == 0){
            minChar = min(minChar, dfs(adj, neighbor, vis));
        }
    }
    return minChar;
}
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.length();
        unordered_map<char, vector<char>> adj;

        for(int i = 0; i<n; i++){
            char u = s1[i];
            char v = s2[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

            string res;
            for(char ch : baseStr){
                vector<int> vis(26, 0);
                char minChar = dfs(adj, ch, vis);
                res.push_back(minChar);
            }
            return res;
        
    }
};