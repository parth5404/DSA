class Solution {
    public boolean isTrionic(int[] nums) {
        int n = nums.length;
        int i = 1;
        while (i < n && nums[i - 1] < nums[i])
            i++;
        if (i - 1 == 0)
            return false;
        while (i < n && nums[i - 1] > nums[i])
            i++;
        if (i-1 == n - 1)
            return false;
        while (i < n && nums[i-1] < nums[i])
            i++;

        return i-1 == n - 1;
    }
}
