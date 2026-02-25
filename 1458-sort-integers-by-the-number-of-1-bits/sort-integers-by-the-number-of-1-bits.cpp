class Solution {
public:
    static int calc(int a) {
        int one = 0;
        while (a != 0) {
            if (a & 1)
                one++;
            a = a / 2;
        }
        return one;
    }
    static bool comp(int& a, int& b) {
        if (calc(a) == calc(b))
            return a < b;
        return calc(a) < calc(b);
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(begin(arr), end(arr), comp);
        return arr;
    }
};
