class Solution {
    public int [][] dp;
    public int solve(int[] prices,boolean sell,int i){
        if(i>=prices.length){
            if(sell==true)return prices[prices.length-1];
            return 0;
        }
        if(dp[i][sell?1:0]!=Integer.MIN_VALUE)return dp[i][sell?1:0];
        int ret_buy=0;
        int ret_nom=0;
        if(sell==false){
            ret_buy=-prices[i]+solve(prices,true,i+1);
        }
        else{
            ret_nom=prices[i]+solve(prices,false,i+1);
        }
        int profit=solve(prices,sell,i+1);
        return dp[i][sell?1:0]= Math.max(ret_buy,Math.max(ret_nom,profit));
    }

    public int maxProfit(int[] prices) {
        this.dp=new int[prices.length+1][2];
        for (int i = 0; i < dp.length; i++) {
            for (int j = 0; j < dp[0].length; j++) {
                dp[i][j] = Integer.MIN_VALUE;
            }
        }
        return solve(prices, false, 0);
    }
}