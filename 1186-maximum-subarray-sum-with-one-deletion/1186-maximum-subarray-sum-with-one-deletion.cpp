class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int noDelete = arr[0];
        int oneDelete = 0;
        int result = arr[0];
        for(int i=1; i< arr.size(); i++){
            int v1 = noDelete + arr[i];
            int v2 = arr[i];
            int v3 = oneDelete + arr[i];
            oneDelete = max(v3, noDelete);
            noDelete = max(v1,v2);
            result = max(result,max(noDelete, oneDelete));
        }
        return result;
    }
};