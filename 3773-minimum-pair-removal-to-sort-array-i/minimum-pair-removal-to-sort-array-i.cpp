class Solution {
public:
    bool isValid(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1])
                return false;
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int cnt = 0;

        while (!isValid(nums)) {
            priority_queue<pair<int, int>, vector<pair<int, int>>,
                           greater<pair<int, int>>>
                pq;
            for (int i = 0; i < nums.size() - 1; i++) {
                pq.push({nums[i] + nums[i + 1], i});
            }
            auto p = pq.top();
            pq.pop();
            int idx = p.second;
            nums[idx] = nums[idx] + nums[idx + 1];
            nums.erase(nums.begin() + idx + 1);
            cnt++;
        }

        return cnt;
    }
};
