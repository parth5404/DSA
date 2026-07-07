class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        string ans="";
        string s=to_string(n);
        for(int i=0;i<s.length();i++){
            if(s[i]!='0'){
                ans+=s[i];
                sum+=(s[i]-'0');
            }
        }
        if(ans.length()==0)return 0;
        return (long long)stoll(ans)*sum;
    }
};