class EventManager {
public:
    struct Compare {
        bool operator()(pair<int, int> a, pair<int, int> b) {
            if (a.first != b.first)
                return a.first < b.first;
            return a.second > b.second;
        }
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
    unordered_map<int, int> mp;
    EventManager(vector<vector<int>>& events) {
        for (auto it : events) {
            mp[it[0]] = it[1];
            pq.push({it[1], it[0]});
        }
    }

    void updatePriority(int eventId, int newPriority) {
        mp[eventId] = newPriority;
        pq.push({newPriority, eventId});
    }

    int pollHighest() {
        while (!pq.empty()) {
            auto top = pq.top();
            if (mp[top.second] != top.first) {
                pq.pop();
            } else {
                break;
            }
        }
        if (!pq.empty()) {
            auto top = pq.top();
            mp.erase(top.second);
            pq.pop();
            return top.second;
        }
        return -1;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */