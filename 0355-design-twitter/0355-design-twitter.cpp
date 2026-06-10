struct cmp{
    bool operator()(const vector<int>&a, const vector<int>&b){
        return a[0] < b[0];
    }
};

class Twitter {
    int count;
    unordered_map<int, vector<vector<int>>> tweetMap;
    unordered_map<int, set<int>> followMap;
public:
    Twitter() {
        int count = 0;    
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({count++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        priority_queue<
            vector<int>,
            vector<vector<int>>,
            cmp
        >pq;

        followMap[userId].insert(userId);
        for(int followeeId : followMap[userId]){
            if(tweetMap.count(followeeId)){
                const vector<vector<int>> &tweets = tweetMap[followeeId];
                int idx = tweets.size() - 1;
                pq.push({tweets[idx][0], tweets[idx][1], followeeId, idx});
            }
        }

        while(!pq.empty() && ans.size() < 10){
            vector<int> curr = pq.top();
            pq.pop();
            ans.push_back(curr[1]);
            int idx = curr[3];
            if(idx > 0){
                const vector<int>& tweet = tweetMap[curr[2]][idx - 1];
                pq.push({tweet[0], tweet[1], curr[2], idx - 1});
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */