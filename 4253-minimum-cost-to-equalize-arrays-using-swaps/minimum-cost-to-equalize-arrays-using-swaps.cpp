class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mp1(80001), mp2(80001);

        for (int i = 0; i < nums1.size(); i++) {
            mp1[nums1[i]]++;
            mp2[nums2[i]]++;
        }
        int ans = 0;
        int diff = 0;
        for (int i = 0; i < mp1.size(); i++) {
            if ((mp1[i] + mp2[i]) % 2 == 1)
                return -1;
            int sum = mp1[i] + mp2[i];
            int req = sum / 2;
            if (req == mp1[i])
                continue;
            diff += (mp1[i] - req);
            ans += abs(mp1[i] - req);
        }
        if(diff==0)return ans/2;
        return ans;
    }
};