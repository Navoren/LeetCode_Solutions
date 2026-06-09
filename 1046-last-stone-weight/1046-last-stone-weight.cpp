class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<
            pair<int,int>
        > pq;

        for(int i=0; i<stones.size(); i++){
            pq.push({stones[i], i});
        }

        while(pq.size() > 1){
            int weight1 = pq.top().first;
            int stone1 = pq.top().second;
            pq.pop();

            int weight2 = pq.top().first;
            int stone2 = pq.top().second;
            pq.pop();

            if(weight1 != weight2){
                pq.push({weight1 - weight2, stone1});
            }
        }

        return pq.empty() ? 0 : pq.top().first;;
    }
};