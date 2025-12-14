1class Solution {
2public:
3    // int countvow(string str) {
4    //     int ans = 0;
5    //     for (char ch : str) {
6    //         if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
7    //             ans++;
8    //     }
9    //     return ans;
10    // }
11    string reverseWords(string s) {
12        int i = 0;
13        int j = 0;
14        bool first = true;
15        int vow = 0;
16        int curr_vow=0;
17        string ans = "";
18        while (j < s.length()) {
19            if (s[j] == ' ') {
20                //string temp = s.substr(i, j - i);
21                if (first) {
22                    first = !first;
23                    vow = curr_vow;
24                } else {
25                    if (curr_vow == vow) {
26                       // cout << temp << endl;
27                        reverse(s.begin()+i, s.begin()+(j));
28                    }
29                }
30                curr_vow=0;
31                //ans = ans + temp + " ";
32                i = j + 1;
33            }
34            if(s[j]=='a'||s[j]=='e'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u')curr_vow++;
35            j++;
36        }
37        //string temp = s.substr(i, j - i);
38        if (curr_vow == vow) {
39//            cout << temp << endl;
40            reverse(s.begin()+i, s.end());
41        }
42    
43        return s;
44    }
45};