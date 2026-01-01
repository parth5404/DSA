class Solution {
    public int[] plusOne(int[] digits) {
        int n = digits.length;
        int[] arr = new int[n + 1];
        int carry = 1;

        for (int i = n - 1; i >= 0; i--) {
            arr[i+1] = digits[i] + carry;
            carry = arr[i+1] / 10;
            arr[i + 1] = arr[i+1] % 10;
        }

        arr[0] = carry;

        if (arr[0] == 0) {
            int[] ret = new int[n];
            for (int i = 1; i <= n; i++) {
                ret[i - 1] = arr[i];
            }
            return ret;
        }

        return arr;
    }
}
