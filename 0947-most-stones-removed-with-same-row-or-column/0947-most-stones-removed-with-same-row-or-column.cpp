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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int stonesRemoved = 0;
        DisjointSet ds(n);
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(stones[i][0] == stones[j][0] ||
                   stones[i][1] == stones[j][1]) {
                    ds.unionByRank(i, j);
                }
            }
        }
        for(int i=0; i<n; i++){
            if(ds.parent[i] == i) stonesRemoved++;
        }

        return n - stonesRemoved;
    }
};