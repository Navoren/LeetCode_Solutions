class Solution {
public:

bool possible(vector<int>& arr, int day, int k, int m){
    int cnt = 0;
    int noOfBloom = 0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i]<=day) cnt++;
        else{
            noOfBloom += (cnt/k);
            cnt = 0;
        }
    }
    noOfBloom += (cnt/k);
    return noOfBloom>=m;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(1ll*m*k>1ll*bloomDay.size()) return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        while(low <= high){
            int mid = low + (high-low)/2;
            if(possible(bloomDay, mid, k, m)) high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};