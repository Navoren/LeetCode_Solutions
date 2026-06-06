class DisjointSet{
    public:
    vector<int> parent, rank;
    DisjointSet(int n){
        rank.resize(n, 0);
        parent.resize(n+1);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }
    int findUPar(int node){
        if(parent[node] == node) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v){
        int ult_u = findUPar(u);
        int ult_v = findUPar(v);
        if(ult_u == ult_v) return;
        if(rank[ult_u] < rank[ult_v]){
            parent[ult_u] = ult_v;
        }else if(rank[ult_v] < rank[ult_u]){
            parent[ult_v] = ult_u;
        }else{
            parent[ult_v] = ult_u;
            rank[ult_u]++;
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int cableExtra = 0;
        DisjointSet ds(n);
        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            if(ds.findUPar(u) == ds.findUPar(v)) cableExtra++;
            ds.unionByRank(u,v);
        }

        int componentCount = 0;
        for(int i=0; i<n; i++){
            if(ds.parent[i] == i) componentCount++; 
        }

        int ans = componentCount-1;
        if(cableExtra < ans) return -1;
        return ans;

    }
};