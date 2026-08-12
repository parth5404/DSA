class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> max_q;
        deque<int> min_q;
        int ans = 1;
        int left=0;
        for (int i = 0; i < nums.size(); i++) {
            while (!max_q.empty() && nums[i] >= nums[max_q.back()]) {
                max_q.pop_back();
            }
            while (!min_q.empty() && nums[i] <= nums[min_q.back()]) {
                min_q.pop_back();
            }
            max_q.push_back(i);
            min_q.push_back(i);
            while(nums[max_q.front()]-nums[min_q.front()]>limit){
                if(max_q.front()==left)max_q.pop_front();
                if(min_q.front()==left)min_q.pop_front();
                left++;
            }
            ans=max(ans,i-left+1);
        }  
        return ans;
    }
};