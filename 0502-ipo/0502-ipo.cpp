class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> projects;

        for(int i = 0; i< profits.size(); i++){
            projects.emplace_back(capital[i], profits[i]);
        }

        sort(projects.begin(), projects.end());

        priority_queue<int> maxHeap;
        int i = 0;
        for(int j=0; j<k; j++){
            while(i<profits.size() && projects[i].first <=w){
                maxHeap.push(projects[i].second);
                i++;
            }
            if(maxHeap.empty()) break;

            w += maxHeap.top();
            maxHeap.pop();
        }

        return w;
    }
};