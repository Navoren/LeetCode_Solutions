class NumArray {
int n;
vector<int> tree;
void build(int node, int l, int r, vector<int>&arr){
        if(l == r){
            tree[node] = arr[l];
            return;
        }
        
        int mid = l + (r - l) / 2;
        build(2*node+1, l, mid, arr);
        build(2*node+2, mid+1, r, arr);
        
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

int query(int node, int l, int r, int ql ,int qr){
    if(r < ql || l > qr) return 0;
    if(r <= qr && l >= ql) return tree[node];

    int mid = l + (r - l) / 2;
    int left = query(2*node+1, l, mid, ql ,qr);
    int right = query(2*node+2, mid+1, r, ql ,qr);

    return left + right;
}
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.resize(4*n);
        build(0, 0,n-1, nums);
    }
    
    int sumRange(int left, int right) {
        return query(0, 0, n-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */