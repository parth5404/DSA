#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // dp[idx][cnt] = {max_weight, vector_of_indices}
    vector<vector<pair<long long, vector<int>>>> dp;
    vector<vector<pair<long long, vector<int>>>> visited; // track memoized state

    // Helper: compare if option 1 is strictly better than option 2
    bool isBetter(long long w1, const vector<int>& idx1, long long w2, const vector<int>& idx2) {
        if (w1 != w2) return w1 > w2; // Higher weight preferred
        return idx1 < idx2;           // Lexicographically smaller indices preferred
    }

    pair<long long, vector<int>> solve(int idx, const vector<vector<int>>& arr, int cnt) {
        // Base Case: Array end ho gaya ya 4 intervals chun liye
        if (idx >= arr.size() || cnt == 4) {
            return {0, {}};
        }

        // Memoization check
        if (dp[idx][cnt].first != -1) {
            return dp[idx][cnt];
        }

        // Option 1: Skip current interval
        auto skip = solve(idx + 1, arr, cnt);

        // Option 2: Pick current interval
        int cutoff = arr[idx][1]; // current interval end time

        // Binary search for first interval starting strictly after cutoff
        int s = idx + 1, e = arr.size();
        while (s < e) {
            int mid = s + (e - s) / 2;
            if (arr[mid][0] > cutoff) {
                e = mid;
            } else {
                s = mid + 1;
            }
        }
        int next_idx = s;

        auto next_res = solve(next_idx, arr, cnt + 1);
        
        long long pick_w = arr[idx][2] + next_res.first;
        vector<int> pick_idx = next_res.second;
        pick_idx.push_back(arr[idx][3]); // Push original index
        sort(pick_idx.begin(), pick_idx.end());

        // Select optimal choice based on weight and tie-breaker
        pair<long long, vector<int>> best;
        if (isBetter(pick_w, pick_idx, skip.first, skip.second)) {
            best = {pick_w, pick_idx};
        } else {
            best = skip;
        }

        return dp[idx][cnt] = best;
    }

    vector<int> maximumWeight(vector<vector<int>>& inter) {
        int n = inter.size();
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            // Store: [start, end, weight, original_index]
            arr[i] = {inter[i][0], inter[i][1], inter[i][2], i};
        }

        // Sort by start time for Binary Search
        sort(arr.begin(), arr.end(), [](const auto& a, const auto& b) {
            if (a[0] != b[0]) return a[0] < b[0];
            if (a[1] != b[1]) return a[1] < b[1];
            return a[3] < b[3];
        });

        // Initialize DP table with -1 weight
        dp = vector<vector<pair<long long, vector<int>>>>(n + 1, vector<pair<long long, vector<int>>>(5, {-1, {}}));

        auto res = solve(0, arr, 0);
        return res.second;
    }
};