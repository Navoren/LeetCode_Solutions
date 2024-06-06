class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() < groupSize || hand.size()%groupSize != 0) return false;

        unordered_map<int,int> cardCount;

        for(auto i:hand) cardCount[i]++;
        
        sort(hand.begin(), hand.end());

        for(auto i : hand){
            if(cardCount[i] == 0) continue;

            bool flag = 1;

            for(int k=0; k<groupSize; k++){
                if(cardCount[i+k] <=0 ){
                    flag = 0;
                    break;
                }
                else cardCount[i+k]--;
            }
            if(!flag) return false;
        }
        return true;
    }
};