class Solution {
public:

bool isPossible(vector<int>& arr, int dist, int ball){
    int countBall = 1;
    int lastPlaced = arr[0];
    for(int i = 1; i<arr.size(); i++){
        if(arr[i] - lastPlaced >= dist){
        countBall++;
        lastPlaced = arr[i];
        }
        if(countBall >= ball){
            return true;
        }
    }
    return false;
}

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int low = 1;
        int high = (position.back()- position[0]) / (m-1);
        int ans = 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isPossible(position, mid, m)){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};