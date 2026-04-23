class Task {
public:
    int et;
    int pt;
    int idx;

    Task(int et, int pt, int idx) {
        this->et = et;
        this->pt = pt;
        this->idx = idx;
    }
};

class Solution {
public:
    static bool cmp(const Task& a, const Task& b) {
        if (a.et != b.et)
            return a.et < b.et;
        return a.pt < b.pt;
    }
    struct cmp1 {
        bool operator()(const Task& a, const Task& b) {
            if (a.pt == b.pt) return a.idx > b.idx;
            return a.pt > b.pt; 
        }
    };
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<Task> arr;
        for (int i = 0; i < tasks.size(); i++) {
            arr.push_back(Task(tasks[i][0], tasks[i][1], i));
        }
        sort(arr.begin(), arr.end(), cmp);
        vector<int> res;
        res.push_back(arr[0].idx);
        long long time = arr[0].et + arr[0].pt;
        priority_queue<Task, vector<Task>, cmp1> pq;
        int i=1;
        while (!pq.empty() || i<arr.size()) {
            if (pq.empty() && time < arr[i].et) {
                time = arr[i].et;
            }
            while(i<arr.size() && time>=arr[i].et){
                pq.push(arr[i]);
                i++;
            }
            res.push_back(pq.top().idx);
            time+=pq.top().pt;
            pq.pop();

        }
        return res;
    }
};