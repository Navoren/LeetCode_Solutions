class Solution {
public:
    string isPossible(int n, vector<int>freq, string curr, char &mid, string& target){
        for(int i=25; i>=0; i--){
            while(freq[i]){
                curr += (char)('a' + i);
                freq[i]--;
            }
        }

        if(mid != '#'){
            string temp = curr;
            curr += mid;
            reverse(temp.begin(), temp.end());
            curr.append(temp.begin(), temp.end());
        }else{
            string temp = curr;
            reverse(temp.begin(), temp.end());
            curr.append(temp.begin(), temp.end());
        }

        return curr > target ? curr : "";
    }
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> freq(26,0);

        if(n == 1){
            if(s > target) return s;
            else return "";
        }

        for(char it : s){
            freq[it - 'a']++;
        }

        char mid = '#';
        int oddCount = 0;

        for(int i = 0; i<26; i++){
            if(freq[i]%2){
                mid = (char)('a'+i);
                freq[i]--;
                oddCount++;
            }

            freq[i] /= 2;
            if(oddCount >= 2) return "";
        }

        n/= 2;
        string res = "";
        string prefix = "";

        for(int i=0; i<n; i++){
            string curr = prefix;
            bool isThereAny = false;

            for(int j=0; j<26; j++){
                if(freq[j]){
                    freq[j]--;
                    curr += (char)('a' + j);

                string isPos = isPossible(n, freq, curr, mid, target);

                if(isPos != ""){
                    prefix = curr;
                    isThereAny = true;

                    if(res == "") res = isPos;
                    else res = min(res, isPos);
                    break;
                }

                freq[j]++;
                curr.pop_back();
            }
        }

        if(!isThereAny) return "";
        }
        return res;
    }
};