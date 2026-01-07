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
    long long ans = 0;
    long long globalsum = 0;
    int mod=1e9+7;
    long long sum(TreeNode* root, int val) {
        if (!root)
            return 0;
        return root->val + sum(root->left, 0) + sum(root->right, 0);
    }
    long long solve(TreeNode* root, int sum) {
        if (!root)
            return 0;
        // sum += root->val;
        long long leftsum = solve(root->left, 0);
        long long rightsum = solve(root->right, 0);
        // if (first) {
        //     globalsum = root->val + leftsum + rightsum;
        // }
        ans = max(ans, max((globalsum - leftsum) * leftsum,
                           (globalsum - rightsum) * rightsum));
        return root->val + leftsum + rightsum;
    }
    int maxProduct(TreeNode* root) {

        // cout<<globalsum<<" "<<sum(root,0)<<endl;
        globalsum = sum(root, 0);
        solve(root, 0);
        return ans%mod;
    }
};