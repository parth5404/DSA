class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = target.length();
        vector<int> freq(26, 0);
        for (int i = 0; i < s.length(); i++)
            freq[s[i] - 'a']++;

        int best =
            -1; // deepest position jahan strictly bada char rakh sakte the
        for (int i = 0; i < n; i++) {
            int idx = target[i] - 'a';

            // (a) yahan target[i] se STRICTLY bada char hai? to ye candidate
            // hai
            for (int j = idx + 1; j < 26; j++) {
                if (freq[j] > 0) {
                    best = i;
                    break;
                }
            }

            // (b) exact match kar ke prefix aage badh sakte hain?
            if (freq[idx] > 0)
                freq[idx]--;
            else
                break; // nahi → prefix yahin khatam
        }

        if (best == -1)
            return ""; // koi position feasible nahi

        // best ke liye freq dobara banao: original minus target[0..best-1]
        for (int i = 0; i < 26; i++)
            freq[i] = 0;
        for (int i = 0; i < s.length(); i++)
            freq[s[i] - 'a']++;
        for (int i = 0; i < best; i++)
            freq[target[i] - 'a']--;

        string ans = target.substr(0, best); // exact prefix
        for (int j = target[best] - 'a' + 1; j < 26;
             j++) { // smallest strictly bada char
            if (freq[j] > 0) {
                freq[j]--;
                ans += char('a' + j);
                break;
            }
        }
        for (int i = 0; i < 26; i++) { // baaki sorted ascending
            while (freq[i] > 0) {
                ans += char('a' + i);
                freq[i]--;
            }
        }
        return ans;
    }
};