class TreeAncestor {
vector<vector<int>> up;
public:
    TreeAncestor(int n, vector<int>& parent) {
        up.resize(n, vector<int>(20, -1));
        for(int i=0; i<n; i++) up[i][0] = parent[i];
        for(int j=1; j<20; j++){
            for(int node=0; node <n; node++){
                if(up[node][j-1] != -1){
                    up[node][j] = up[up[node][j-1]][j-1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int j=0; j<20; j++){
            if(k&(1 << j)){
                node = up[node][j];
                if(node == -1) return -1;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */