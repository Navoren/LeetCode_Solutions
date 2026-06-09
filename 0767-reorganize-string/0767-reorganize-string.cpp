class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> freq;

        for(char c : s)
            freq[c]++;

        priority_queue<pair<int,char>> pq; // (freq, char)

        for(auto &it : freq)
            pq.push({it.second, it.first});

        string ans;

        while(pq.size() > 1) {
            auto [freq1, letter1] = pq.top();
            pq.pop();

            auto [freq2, letter2] = pq.top();
            pq.pop();

            ans += letter1;
            ans += letter2;

            if(--freq1 > 0)
                pq.push({freq1, letter1});

            if(--freq2 > 0)
                pq.push({freq2, letter2});
        }

        if(!pq.empty()) {
            auto [f, c] = pq.top();

            if(f > 1)
                return "";

            ans += c;
        }

        return ans;
    }
};