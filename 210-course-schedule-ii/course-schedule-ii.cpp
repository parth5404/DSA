class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        unordered_map<int, vector<int>> mp;
        vector<int> indegree(numCourses, 0);
        vector<int>vis(numCourses, 0);
        for (auto it : pre) {
            mp[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        queue<int> q;
        vector<int> ans;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int top = q.front();
            q.pop();
            vis[top]=1;
            ans.push_back(top);
            for (auto it : mp[top]) {
                indegree[it]--;
                if (indegree[it] == 0 && vis[it]==0) {
                    q.push(it);
                }
            }
        }
        for(auto it:indegree){
            if(it>0)return {};
        }
        return ans;
    }
};