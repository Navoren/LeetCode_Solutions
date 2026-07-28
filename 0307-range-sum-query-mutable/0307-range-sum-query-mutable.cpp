class NumArray {
private:
    vector<int>seg;
    int n;

    void build(int nodeIdx, int l, int r, vector<int>& nums){
        if(l == r){
            seg[nodeIdx] = nums[l];
            return;
        }

        int mid = (l + r)/2;
        build(2*nodeIdx+1, l, mid, nums);
        build(2*nodeIdx+2, mid+1, r, nums);
        seg[nodeIdx] = seg[2*nodeIdx+1] + seg[2*nodeIdx+2];
    }

    void updateTree(int nodeIdx, int l, int r, int idx, int val){
        if(l == r){
            seg[nodeIdx] = val;
            return;
        }

        int mid = (l+r)/2;

        if(idx <= mid){
            updateTree(2*nodeIdx +1, l, mid, idx, val);
        }else{
            updateTree(2*nodeIdx+2, mid+1, r, idx, val);
        }

        seg[nodeIdx] = seg[2*nodeIdx + 1] + seg[2*nodeIdx + 2];
    }

    int query(int nodeIdx, int l, int r, int ql, int qr){
        if(r < ql || l > qr) return 0;
        if(r <= qr && l >= ql) return seg[nodeIdx];

        int mid = (l + r)/2;
        int left = query(2*nodeIdx+1, l, mid, ql, qr);
        int right = query(2*nodeIdx+2, mid+1, r, ql ,qr);

        return left + right;
    }
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.resize(4*n);

        if(n > 0){
            build(0,0, n-1, nums);
        }
    }
    
    void update(int index, int val) {
        updateTree(0,0, n-1, index, val);
    }
    
    int sumRange(int left, int right) {
        return query(0,0, n-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */