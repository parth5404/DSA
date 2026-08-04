class Solution {
public:
    vector<int> countTasks(vector<int>& ts, vector<int>& sh) {
        vector<long long> pref(ts.size());
        pref[0] = ts[0];

        for (int i = 1; i < ts.size(); i++)
            pref[i] = pref[i - 1] + ts[i];

        long long wd = 0;
        vector<int> arr(sh.size());

        for (int i = 0; i < sh.size(); i++) {
            // {
            //     // vector<long long>::iterator it = pref.begin();

            //     // if (lst == -1)
            //     //     it = lower_bound(pref.begin(), pref.end(), sh[i] -
            //     //     carry);
            //     // else
            //     //     it = lower_bound(pref.begin(), pref.end(),
            //     //                      sh[i] - carry + pref[lst]);

            //     // int idx = it - pref.begin();
            //     // if (it == pref.end() || idx == pref.size() - 1) {
            //     //     cout << "Here" << endl;
            //     //     arr[i] = 0;
            //     //     carry = 0;
            //     //     lst = -1;
            //     //     continue;
            //     // }

            //     // carry = pref[idx] - sh[i];
            //     // cout << carry << "  " << idx << endl;
            //     // lst = idx;
            //     // if (carry == 0)
            //     //     arr[i] = pref.size() - (lst + 1);
            //     // arr[i] = pref.size() - lst;}
            // }
            wd = wd + sh[i];
            if (wd >= pref.back()) {
                arr[i] = 0;
                wd = 0;
            } else {
                auto it = upper_bound(pref.begin(), pref.end(), wd);
                arr[i] = pref.size() - (it - pref.begin());
            }
        }

        return arr;
    }
};