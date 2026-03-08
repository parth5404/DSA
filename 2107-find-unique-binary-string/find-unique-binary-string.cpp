class Solution {
public:
    long long to_val(string& a) {
        long long val = 0;
        for (char c : a) {
            val = val * 2 + (c - '0');
        }
        return val;
    }

    string to_str(long long val, int n) {
        string str = "";

        while (val > 0) {
            str += (val % 2) + '0';
            val /= 2;
        }

        reverse(str.begin(), str.end());

        while (str.length() < n) {
            str = "0" + str;
        }

        return str;
    }

    static bool comp(string& a, string& b) {
        long long val1 = 0;
        long long val2 = 0;

        for (char c : a)
            val1 = val1 * 2 + (c - '0');
        for (char c : b)
            val2 = val2 * 2 + (c - '0');

        return val1 < val2;
    }

    string findDifferentBinaryString(vector<string>& nums) {

        int n = nums.size();
        sort(nums.begin(), nums.end(), comp);

        for (int i = 1; i < nums.size(); i++) {
            if (to_val(nums[i]) - to_val(nums[i - 1]) != 1) {
                long long val = to_val(nums[i - 1]) + 1;
                return to_str(val, n);
            }
        }

        long long val1 = to_val(nums[0]);
        long long val2 = to_val(nums.back());
        if (val1 - 1 >= 0) {
            return to_str(val1-1, n);
        }
        return to_str(val2+1,n);
    }
};