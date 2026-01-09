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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return nullptr;
        // if ((root->left == p && root->right == q) ||
        //     (root->right == q && root->left == p))
        //     return root;
        if(root==p||root==q)return root;
        TreeNode* west = lowestCommonAncestor(root->right, p, q);
        TreeNode* east = lowestCommonAncestor(root->left, p, q);
        // if (root == p) {
        //     if (west == q || east == q)
        //         return root;
        // } else if (root == q) {
        //     if (west == p || east == p)
        //         return root;
        // }
        if (west && east)return root;
        if(west)return west;
        return east;
    }
};