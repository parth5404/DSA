class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<int> vis(arr.size(), 0);
        queue<int> q;
        q.push(start);

        while (!q.empty()) {
            int top = q.front();
            cout<<top<<endl;
            q.pop();
            vis[top] = 1;
            if (arr[top] == 0)
                return true;
            if (top + arr[top] < arr.size() && vis[top + arr[top]] == 0)
                q.push(top + arr[top]);
            if (top - arr[top] >= 0 && vis[top - arr[top]] == 0) {
                q.push(top - arr[top]);
            }
        }
        return false;
    }
};