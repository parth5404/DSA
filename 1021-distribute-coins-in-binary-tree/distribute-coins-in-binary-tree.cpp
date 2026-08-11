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
    /*
    -1 -> garreb

    */
    int res = 0;
    int solve(TreeNode* root) {
        if (!root)
            return 0;

        auto left = solve(root->left);
        auto right = solve(root->right);

        if (left >= 0 && right >= 0) {
            res += abs(left) + abs(right);
            return root->val + left + right - 1;
        }
        if ((left >= 1 && right < 0) || (left < 0 && right >= 1)) {
            int sum = root->val + left + right;
            int extra = sum - 1;
            res += abs(left) + abs(right);
            return sum - 1;
        }
        if ((left < 0 && right < 0)) {
            int sum = root->val + left + right;
            int extra = sum - 1;
            res += abs(left) + abs(right);
            return sum - 1;
        }
        res += abs(left) + abs(right);
        return root->val + left + right - 1;
    }
    int distributeCoins(TreeNode* root) {
        solve(root);
        return res;
    }
};