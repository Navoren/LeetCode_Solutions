class DisjointSet {
public: 
    vector<int> parent, rank;

    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1, 1);

        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }

    int findUPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        DisjointSet ds(n);

        for(auto&it : edges){
            int u = it[0];
            int v = it[1];

            if(ds.findUPar(u) == ds.findUPar(v))
            return{u,v};

            ds.unionByRank(u,v);
        }

        return {};
    }
};