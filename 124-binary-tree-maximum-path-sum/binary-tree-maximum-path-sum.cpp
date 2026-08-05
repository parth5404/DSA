/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int val = INT_MIN;
    int solve(TreeNode* root) {
        if (!root)
            return 0;
        int leftmax = max(0, solve(root->left));
        int rightmax = max(0, solve(root->right));
        val = max(val, root->val + leftmax + rightmax);
        return root->val + max(leftmax, rightmax);
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return val;
    }
};