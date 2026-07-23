class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) {
            return n;
        }
        int cnt_bits = 0;
        while (n != 0) {
            cnt_bits++;
            n = n / 2;
        }
        return (int)pow(2, cnt_bits);
    }
};