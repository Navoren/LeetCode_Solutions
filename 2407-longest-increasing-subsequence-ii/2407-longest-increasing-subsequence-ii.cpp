class SegmentTree{
public:
    int limit;
    vector<int> tree;
    SegmentTree(int mx){
       limit = mx;
        tree.resize(4*(mx+1));
    }
    
    // void build(int node, int l, int r, vector<int>&arr){
    //     if(l == r){
    //         tree[node] = arr[l];
    //         return;
    //     }
        
    //     int mid = (l+r)/2;
    //     build(2*node, l, mid, arr);
    //     build(2*node+1, mid+1, r, arr);
        
    //     //tree[node] = tree[2 * node] + tree[2 * node + 1];
    //     tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    // }
    
    int query(int node, int l, int r, int ql ,int qr){
        if(r < ql || l > qr) return 0;
        if(r <= qr && l >= ql) return tree[node];
        
        int mid = (l+r)/2;
        int left = query(2*node, l, mid, ql, qr);
        int right = query(2*node+1, mid+1, r, ql ,qr);
        
        //return left + right;
        return max(left, right);
    }
    
    void update(int node, int l, int r, int idx, int val){
        if(l == r){
            tree[node] = max(tree[node], val);
            return;
        }
        
        int mid = (l + r)/2;
        
        if(idx <= mid){
            update(2*node, l, mid, idx, val);
        }else{
            update(2*node+1, mid+1, r, idx, val);
        }
        
        //tree[node] = tree[2*node] + tree[2*node + 1];
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }
    
    int query(int l, int r){
        if(l > r) return 0;
        return query(1, 1, limit, l, r);
    }
    
    void update(int idx, int val){
         update(1, 1, limit, idx, val);
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        SegmentTree ds(mx);
        int ans = 1;
        for(auto x : nums){
            int l = max(1, x-k);
            int r = x - 1;

            int best = ds.query(l, r);
            ds.update(x, best+1);
            ans = max(ans, best+1);
        }

        return ans;
    }
};