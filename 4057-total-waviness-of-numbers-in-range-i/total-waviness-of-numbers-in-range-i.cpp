class Solution {
public:
int solve(int num){
    string s=to_string(num);
    int ans=0;
    for(int i=1;i<s.length()-1;i++){
        if((s[i]>s[i-1] && s[i]>s[i+1])||(s[i]<s[i+1] && s[i]<s[i-1]))ans++;
    }
    return ans;
}
    int totalWaviness(int num1, int num2) {
        int cnt=0;
        for (int i = num1; i <= num2; i++) {
            cnt+=solve(i);
        }
        return cnt;
    }
};