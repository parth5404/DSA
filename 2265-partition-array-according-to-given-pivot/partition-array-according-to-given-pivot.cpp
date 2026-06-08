class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> arr(nums.size());
        int l = 0;
        int r = nums.size() - 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < pivot) {
                arr[l] = nums[i];
                l++;
            }
        }
        if (l <= arr.size() - 1) {
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == pivot) {
                    arr[l] = nums[i];
                    l++;
                }
            }
        }
        if (l <= arr.size() - 1) {
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] > pivot) {
                    arr[l] = nums[i];
                    l++;
                }
            }
        }
        return arr;
    }
};