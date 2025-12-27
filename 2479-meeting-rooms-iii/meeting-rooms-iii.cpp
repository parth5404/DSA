class Solution {
public:
    struct cmp {
        bool operator()(pair<int, long long>& a, pair<int, long long>& b) {
            if (a.second == b.second)
                return a.first > b.first;
            return a.second > b.second;
        }
    };

    int mostBooked(int n, vector<vector<int>>& meet) {
        sort(meet.begin(), meet.end());

        unordered_map<int, int> mp;

        priority_queue<int, vector<int>, greater<int>> rooms;
        for (int i = 0; i < n; i++)
            rooms.push(i);

        priority_queue<pair<int, long long>, vector<pair<int, long long>>, cmp> pq;

        for (int i = 0; i < meet.size(); i++) {

            while (!pq.empty() && pq.top().second <= meet[i][0]) {
                rooms.push(pq.top().first);
                pq.pop();
            }

            long long duration = meet[i][1] - meet[i][0];

            if (!rooms.empty()) {
                int room = rooms.top();
                rooms.pop();
                mp[room]++;
                pq.push({room, meet[i][1]});
            } else {
                auto p = pq.top();
                pq.pop();
                mp[p.first]++;
                pq.push({p.first, p.second + duration}); 
            }
        }

        int ans = INT_MIN;
        int ret_ans = INT_MAX;
        for (auto &it : mp) {
            if (it.second > ans) {
                ans = it.second;
                ret_ans = it.first;
            } else if (it.second == ans) {
                ret_ans = min(ret_ans, it.first);
            }
        }

        return ret_ans;
    }
};
