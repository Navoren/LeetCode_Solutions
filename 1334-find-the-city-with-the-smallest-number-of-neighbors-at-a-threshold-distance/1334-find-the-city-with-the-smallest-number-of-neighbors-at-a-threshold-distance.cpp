class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>>adj(n);

        for(auto &it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        int countCity = n;
        int city = -1;

        for(int i=0; i<n; i++){
            priority_queue<
                pair<int,int>,
                vector<pair<int,int>>,
                greater<pair<int,int>>
            > pq;

            vector<int> dist(n, INT_MAX);

            dist[i] = 0;
            pq.push({0, i});

            while(!pq.empty()){
                auto [dis, u] = pq.top();
                pq.pop();

                if(dis > dist[u]) continue;

                for(auto &[v, wt] : adj[u]){
                    if(dist[u] + wt < dist[v]){
                        dist[v] = dist[u] + wt;
                        pq.push({dist[v], v});
                    }
                }
            }

            int reachable = 0;
            for(int j=0; j<n; j++){
                if(dist[j] <= distanceThreshold){
                    reachable++;
                }
            }

            if(reachable <= countCity){
                city = i;
                countCity = reachable; 
            }
        }
        return city;
    }
};