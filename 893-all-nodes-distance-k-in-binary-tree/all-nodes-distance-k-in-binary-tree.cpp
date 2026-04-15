class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        buildParent(parent, root);

        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;

        q.push(target);
        visited.insert(target);

        while (!q.empty()) {
            int size = q.size();

            if (k == 0) break;
            k--;

            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                if (curr->left && !visited.count(curr->left)) {
                    q.push(curr->left);
                    visited.insert(curr->left);
                }

                if (curr->right && !visited.count(curr->right)) {
                    q.push(curr->right);
                    visited.insert(curr->right);
                }

                if (parent.count(curr) && !visited.count(parent[curr])) {
                    q.push(parent[curr]);
                    visited.insert(parent[curr]);
                }
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }

    void buildParent(unordered_map<TreeNode*, TreeNode*>& parent, TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr->left) {
                parent[curr->left] = curr;
                q.push(curr->left);
            }

            if (curr->right) {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }
};