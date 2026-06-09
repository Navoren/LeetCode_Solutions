class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;

        for (char task : tasks) {
            freq[task]++;
        }

        priority_queue<pair<int, char>> pq;

        for (auto &p : freq) {
            pq.push({p.second, p.first});
        }

        queue<pair<int, pair<int, char>>> cooldown;
        int time = 0;

        while (!pq.empty() || !cooldown.empty()) {
            time++;

            if (!pq.empty()) {
                auto [f, task] = pq.top();
                pq.pop();

                f--;

                if (f > 0) {
                    cooldown.push({time + n, {f, task}});
                }
            }

            if (!cooldown.empty() && cooldown.front().first == time) {
                pq.push(cooldown.front().second);
                cooldown.pop();
            }
        }

        return time;
    }
};