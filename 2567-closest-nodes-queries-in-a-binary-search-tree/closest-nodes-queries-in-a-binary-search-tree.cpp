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
class Solution { //Please upvote if it helps
public:
/*
    void func(TreeNode* root, int &val, int &mini, int &maxi){
        if(root == nullptr) return;
        if(root -> val == val){
            mini = val, maxi = val;
        }else if(root->val < val){
            mini = max(mini,root->val);
            func(root->right, val, mini, maxi);
        }else{//root->val > val
            maxi = min(maxi, root->val);
            func(root->left, val, mini, maxi);
        }
    }
*/
    void inorder(TreeNode* root, vector<int> &arr){
        if(root == nullptr)return;
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> ans;
    /* Actual BST appraoch which will give TLE for the last case, such a dumb question
        for(auto &i : queries){
            int mini = -1, maxi = INT_MAX;
            func(root, i, mini, maxi);
            if(maxi == INT_MAX) maxi = -1;
            ans.push_back({mini, maxi});
        }
    */
        vector<int> arr; //extracting the binary search tree
        inorder(root, arr);
        int n = arr.size();
        for(auto &val : queries){
            int i = lower_bound(arr.begin(), arr.end(), val) - arr.begin();
            if(i < n && arr[i] == val){
                ans.push_back({val, val});
            }else if(i == 0){
                ans.push_back({-1, arr[i]});
            }else if(i == n){
                ans.push_back({arr[i-1], -1});
            }else{
                ans.push_back({arr[i-1], arr[i]});
            }
        }
        return ans;
    }
};