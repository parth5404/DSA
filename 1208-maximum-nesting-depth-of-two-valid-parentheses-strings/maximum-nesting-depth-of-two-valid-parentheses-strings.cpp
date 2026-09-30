class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans(seq.size(), 0);
        int run = 0;
        bool o_place = 0;
        bool c_place = 0;
        for (int i = 0; i < seq.size(); i++) {
            if (seq[i] == '(') {
                ans[i] = (int)(o_place);
                o_place = !o_place;
            } else {
                ans[i] = (int)(c_place);
                c_place = !c_place;
            }
        }
        return ans;
    }
};