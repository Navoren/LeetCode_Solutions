class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int>freq(n+1,0);
        vector<int>res;
        int c=0;
        for(int i=0;i<n;i++){
            if(++freq[A[i]]==2)c++;
            if(++freq[B[i]]==2)c++;
            res.push_back(c);
        }
        return res;
    }
};