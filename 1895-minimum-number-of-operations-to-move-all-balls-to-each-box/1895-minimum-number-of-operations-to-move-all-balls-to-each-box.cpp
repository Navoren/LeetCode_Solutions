class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        vector<int> ans(n,0);
        int balls_to_left = 0, balls_to_right = 0;
        int ops = 0;
        for(int i = 0; i<n; i++){
            ans[i]+= ops;
            balls_to_left += (boxes[i] - '0');
            ops += balls_to_left;
        }
        ops = 0;
        for(int i = n-1; i>=0; i--){
            ans[i] += ops;
            balls_to_right += (boxes[i] - '0');
            ops += balls_to_right;
        }
        return ans;
    }
};