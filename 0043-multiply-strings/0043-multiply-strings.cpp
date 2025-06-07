class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        int n1 = num1.size();
        int n2 = num2.size();
        vector<int> res(n1+n2, 0);

        for(int i = n1-1; i >=0; i--){
            int carry = 0;
            for(int j = n2-1; j>=0; j--){
                int temp = res[i+j+1] + (num1[i] - '0') * (num2[j] - '0') + carry;
                res[i+j+1] = temp%10;
                carry = temp/10;
            }
            res[i] += carry;
        }

        int idx = 0;
        while(idx < res.size() - 1 && res[idx] == 0) idx++;
        string ans;
        ans.reserve(res.size() - idx);
        for(; idx < res.size(); idx++){
            ans.push_back(res[idx] + '0');
        }
        return ans;

    }
};