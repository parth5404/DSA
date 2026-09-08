class Solution {
public:
    bool canPlaceFlowers(vector<int>& fb, int n) {
        int total = 0;
        int prev = -1;
        for (int i = 0; i < fb.size(); i++) {
            if (fb[i] == 0) {
                bool left = (i == 0 || fb[i - 1] == 0);
                bool right = (i + 1 == fb.size() || fb[i + 1] == 0);
                if (left && right) {
                    fb[i] = 1;
                    total++;
                    if (total == n)
                        return true;
                }
            }
        }
        return total >= n;
    }
};