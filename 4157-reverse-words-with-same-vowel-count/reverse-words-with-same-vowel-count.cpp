class Solution {
public:
    // int countvow(string str) {
    //     int ans = 0;
    //     for (char ch : str) {
    //         if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
    //             ans++;
    //     }
    //     return ans;
    // }
    string reverseWords(string s) {
        int i = 0;
        int j = 0;
        bool first = true;
        int vow = 0;
        int curr_vow=0;
        string ans = "";
        while (j < s.length()) {
            if (s[j] == ' ') {
                //string temp = s.substr(i, j - i);
                if (first) {
                    first = !first;
                    vow = curr_vow;
                } else {
                    if (curr_vow == vow) {
                       // cout << temp << endl;
                        reverse(s.begin()+i, s.begin()+(j));
                    }
                }
                curr_vow=0;
                //ans = ans + temp + " ";
                i = j + 1;
            }
            if(s[j]=='a'||s[j]=='e'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u')curr_vow++;
            j++;
        }
        //string temp = s.substr(i, j - i);
        if (curr_vow == vow) {
//            cout << temp << endl;
            reverse(s.begin()+i, s.end());
        }
    
        return s;
    }
};