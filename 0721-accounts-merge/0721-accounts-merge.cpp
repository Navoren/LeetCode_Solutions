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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> mpp;
        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(mpp.find(mail) == mpp.end()){
                    mpp[mail] = i;
                }else{
                    ds.unionByRank(i, mpp[mail]);
                }
            }
        }

        vector<string> mergedMail[n];
        for(auto &it : mpp){
            string mail = it.first;
            int node = ds.findUPar(it.second);
            mergedMail[node].push_back(mail);
        }

        vector<vector<string>> ans;

        for(int i=0; i<n; i++){
            if(mergedMail[i].size() == 0) continue;
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it : mergedMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};