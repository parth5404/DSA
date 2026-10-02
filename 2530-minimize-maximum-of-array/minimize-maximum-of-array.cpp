class Solution {
public:
    bool check(vector<int> nums, int val) {
        vector<long long> arr;
        for (int i : nums) {
            arr.push_back((long long)i);
        }
        long long c_diff = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (arr[i] + c_diff > val) {
                long long diff = arr[i] + c_diff - val;
                arr[i] = val;
                c_diff = diff;
            } else {
                c_diff = 0;
            }
        }
        return c_diff == 0;
    }
    int minimizeArrayValue(vector<int>& nums) {
        int e = *max_element(nums.begin(), nums.end());
        int s = 0;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (check(nums, mid)) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return s;
    }
};