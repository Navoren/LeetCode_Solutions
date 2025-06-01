class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int el1,el2;
        int c1=0,c2= 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(c1==0 && nums[i]!=el2){
                c1++;
                el1 = nums[i];
            }
            else if(c2==0 && nums[i]!=el1){
                c2++;
                el2 = nums[i];
            }
            else if(nums[i]==el1){
                c1++;
            }
            else if(nums[i]==el2){
                c2++;
            }
            else{
                c1--;
                c2--;
            }
    }

    // manual checks 
    c1= 0, c2=0;
    for(int i=0;i<n;i++){
        if(nums[i]==el1)c1++;
        if(nums[i]==el2)c2++;
    }

    int mini = (int)(n/3)+1;
    if(c1>=mini){
        res.push_back(el1);
    }
    if(c2>=mini && el1!=el2){
        res.push_back(el2);
    }

  return res;
}};