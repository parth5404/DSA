class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        string t=to_string(x);
        int i=0;
        int j=t.length()-1;
        while(i<=j){
            if(t[i]!=t[j])return false;
            i++;
            j--;
        }
        return true;
    }
};