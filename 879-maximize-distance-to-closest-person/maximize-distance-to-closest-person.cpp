class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int prev = -1;
        int ans = 0;
        for (int i = 0; i < seats.size(); i++) {
            if (seats[i] == 1) {
                if (prev == -1) {
                    if (i - 1 >= 0) {
                        ans = max(ans, i);
                    }
                    prev=i;
                }
                else{
                    ans=max(ans,(i-prev)/2);
                    prev=i;
                }
            }
        }
        int n=seats.size();
        ans=max(ans,n-1-prev);
        return ans;
    }
};