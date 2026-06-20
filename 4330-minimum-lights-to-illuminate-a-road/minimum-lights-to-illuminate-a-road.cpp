class Solution {
public:
    int minLights(vector<int>& lt) {
        vector<int> arr(lt.size(), 0);
        int cnt = 0;
        int n = lt.size();
        for (int i = 0; i < lt.size(); i++) {
            if (lt[i] > 0) {
                int l = max(0, i - lt[i]);
                int r = min(n - 1, i + lt[i]);
                arr[l] += 1;
                if (r + 1 < n) {
                    arr[r + 1] += -1;
                }
            }
        }

        for (int i = 1; i < arr.size(); i++) {
            arr[i] += arr[i - 1];
        }

        for (int i = 0; i < arr.size(); i++) {
            if (lt[i] == 0 && arr[i] == 0) {
                cnt++;
                arr[i] = 1;
                if (i + 1 < n)
                    arr[i + 1] = 1;
                if (i + 2 < n)
                    arr[i + 2] = 1;
            }
        }

        return cnt;
    }
};