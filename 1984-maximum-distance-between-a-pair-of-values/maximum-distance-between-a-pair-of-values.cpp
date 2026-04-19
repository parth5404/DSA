class Solution {
public:
    int bs(vector<int>& arr, int e, int k) {
        int s = arr.size() - 1;
        int ans = -1;
        while (s >= e) {
            int mid = s + (e - s) / 2;
            if (arr[mid] < k) {
                s = mid - 1;
            } else if (arr[mid] >= k) {
                ans = mid;
                e = mid + 1;
            }
        }
        return ans;
    }
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        for (int i = 0; i < nums1.size(); i++) {
            int idx = bs(nums2, i, nums1[i]);
            if (idx != -1) {
                ans = max(ans, idx - i);
            }
        }
        return ans;
    }
};