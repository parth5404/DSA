class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        //int xori=0;
        for(int i:nums)k=k^i;
        int moves=0;
        while(k!=0){
            if(k%2==1)moves++;
            k=k>>1;
        }
        return moves;
    }
};