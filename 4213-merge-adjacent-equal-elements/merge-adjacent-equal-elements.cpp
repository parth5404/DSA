class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> ans;
        stack<long long>st;
        for (int i = 0; i < nums.size(); i++) {
            long long var=nums[i];
            while(!st.empty() && st.top()==var){
                var=2*st.top();
                st.pop();
            }
            st.push(var);
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};