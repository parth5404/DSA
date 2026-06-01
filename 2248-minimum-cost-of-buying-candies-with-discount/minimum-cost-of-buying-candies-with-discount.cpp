class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int ans=0;
        int i=cost.size()-1;
        while(i>=0){
            if(i>=1){
                ans+=cost[i]+cost[i-1];
            }else{
                ans+=cost[i];
            }
            i=i-3;
        }
        return ans;
    }
};