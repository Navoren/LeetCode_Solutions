class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        int ans = 0, i=0;
        while(i != seats.size()){
            ans += abs(students[i]-seats[i]);
            i++;
        }
        return ans;
    }
};