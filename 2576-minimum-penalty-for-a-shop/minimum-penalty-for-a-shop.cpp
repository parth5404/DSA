class Solution {
public:
    int bestClosingTime(string cus) {
        int sum = 0;
        int ans = INT_MAX;
        for (char& ch : cus) {
            if (ch == 'Y')
                sum++;
        }
        int n_cnt = 0;
        int ret_ans = 0;
        int y_cnt = 0;
        for (int i = 0; i < cus.length(); i++) {

            if (i >= 1) {
                if (cus[i - 1] == 'N')
                    n_cnt++;
                if (cus[i - 1] == 'Y')
                    y_cnt++;
            }

            int val = n_cnt + sum - (y_cnt);        
            cout<<val<<endl;
            if (val < ans) {
                ans = val;
                ret_ans = i;
            }
        }
        if(n_cnt<ans){
            ret_ans=cus.length();
        }

        return ret_ans;
    }
};