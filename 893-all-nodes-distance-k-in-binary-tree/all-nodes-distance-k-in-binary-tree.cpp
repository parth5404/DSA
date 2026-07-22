/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> ans;
    int find(TreeNode* root, TreeNode* target, int k) {
        if (!root)
            return 0;
        if (root == target) {
            dfs(root, k);
            return 1;
        }
        int left = find(root->left, target, k);
        if (left > 0) {
            dfs(root->right, k - left - 1);
            if (left == k)
                ans.push_back(root->val);
            return left + 1;
        }
        int right = find(root->right, target, k);
        if (right > 0) {
            dfs(root->left, k - right - 1);
            if (right == k)
                ans.push_back(root->val);
            return right + 1;
        }
        return -1;
    }
    void dfs(TreeNode* root, int k) {
        if (!root)
            return;
        if (k == 0) {
            ans.push_back(root->val);
            return;
        }
        dfs(root->left, k - 1);
        dfs(root->right, k - 1);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        find(root, target, k);
        return ans;
    }
};