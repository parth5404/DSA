class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool check = n & 1;
        n = n >> 1;
        while (n != 0) {
            if (bool(n & 1) == !check) {
                check = !check;
                n = n >> 1;
            } else {
                return false;
            }
        }
        return true;
    }
};