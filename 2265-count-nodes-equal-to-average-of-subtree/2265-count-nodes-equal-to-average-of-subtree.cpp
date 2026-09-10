/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int ans = 0;
    pair<int,int> inOrder(TreeNode* node){
        if(!node) return {0,0};
        auto [leftSum, leftCount] = inOrder(node->left);
        auto [rightSum, rightCount] = inOrder(node->right);

        int sum = leftSum + rightSum + node->val;
        int cnt = leftCount + rightCount + 1;
        if(sum/cnt == node->val) ans++;
        return {sum, cnt};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        inOrder(root);
        return ans;
    }
};