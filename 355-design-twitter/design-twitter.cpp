class Twitter {
    struct cmp {
        bool operator()(array<int, 2> a, array<int, 2> b) {
            return a[1] < b[1];
        }
    };

public:
    unordered_map<int, unordered_set<int>> mp1;
    unordered_map<int, vector<array<int, 2>>> mp2;

    int cnt = 0;
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        mp2[userId].push_back({tweetId, cnt});
        cnt++;
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<array<int, 2>, vector<array<int, 2>>, cmp> pq;

        vector<int> ans;
        auto st = mp1[userId];
        st.insert(userId);
        for (auto it : st) {
            for (auto it1 : mp2[it]) {
                pq.push(it1);
                // if (pq.size() > 10) {
                //     pq.pop();
                // }
            }
        }
        int cnt = 10;
        while (!pq.empty() && cnt--) {
            ans.push_back(pq.top()[0]);
            pq.pop();
        }
        return ans;
    }

    void follow(int followerId, int followeeId) {
        mp1[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        mp1[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */