class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1, high = *max_element(piles.begin(), piles.end());
        while(low < high){
            int mid = low + (high-low)/2;
            int total = 0;
            for(int pile : piles){
                total = total + ceil((double)pile/mid);
            }
            if(total > h) low = mid+1;
            else high = mid;
        }
        return low;
    }
};