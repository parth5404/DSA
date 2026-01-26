class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int min_diff = INT_MAX;
        for (int i = 0; i < arr.size() - 1; i++) {
            min_diff=min(min_diff,arr[i+1]-arr[i]);
        }
        unordered_set<int> st(arr.begin(), arr.end());
        vector<vector<int>> ans;
        for (int i = 0; i < arr.size(); i++) {
            if(st.find(arr[i]+min_diff)!=st.end()){
                ans.push_back({arr[i],arr[i]+min_diff});
            }
        }
        return ans;
    }
};