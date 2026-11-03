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
    int cnt(TreeNode* root) {
        if (!root)
            return 0;
        int l1 = ld(root);
        int r1 = rd(root);
        if (l1 == r1) {
            return (1 << l1) - 1;
        }
        return 1 + cnt(root->left) + cnt(root->right);
    }
    int ld(TreeNode* root) {
        int ht = 0;
        while (root != nullptr) {
            ht++;
            root = root->left;
        }
        return ht;
    }
    int rd(TreeNode* root) {
        int ht = 0;
        while (root != nullptr) {
            ht++;
            root = root->right;
        }
        return ht;
    }
    int countNodes(TreeNode* root) { return cnt(root); }
};