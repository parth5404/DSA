class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> vec(101, 0);
        int max_yr = -1;
        for (int i = 0; i < logs.size(); i++) {
            max_yr = max(max_yr, logs[i][1]);
            vec[logs[i][0] - 1950] += 1;
            vec[logs[i][1] - 1950] += -1;
        }
        int maxi = vec[0];
        int ret_ans = 1950;
        for (int i = 1; i < vec.size(); i++) {
            if (i + 1950 <= max_yr) {
                vec[i] += vec[i - 1];
                if (vec[i] > maxi) {
                    maxi = vec[i];
                    ret_ans = i + 1950;
                }
            } else if (i + 1950 > max_yr)
                break;
        }
        return ret_ans;
    }
};