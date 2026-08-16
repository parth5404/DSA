class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        array<int, 3> arr = {0, 0, 0};
        for (int i : stones)
            arr[i % 3]++;
        if (arr[0] % 2 == 0) {
            return (arr[1] > 0 && arr[2] > 0);
        }
        return abs(arr[2] - arr[1]) > 2;
    }
};