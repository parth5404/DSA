class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> st;
        unordered_set<int> st1;
        for (int j = 0; j < nums.size(); j++) {
            for (int k = j; k < nums.size(); k++) {
                int xori = nums[j] ^ nums[k];
                st.insert(xori);
            }
        }
        for (auto it : st) {
            for (int i = 0; i < nums.size(); i++) {
                st1.insert(it ^ nums[i]);
            }
        }

        return st1.size();
    }
};