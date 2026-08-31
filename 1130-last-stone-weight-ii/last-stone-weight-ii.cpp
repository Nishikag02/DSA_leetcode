class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {

        int n=stones.size();
        int totalSum=0;

        for(int el:stones){
            totalSum+=el;
        }

        int W=totalSum/2;

        vector<vector<int>>dp(n+1,vector<int>(W+1,0));

        for(int i=1;i<n+1;i++){
            for(int j=1;j<W+1;j++){
                if(stones[i-1]<=j){
                    dp[i][j]=max(dp[i-1][j],stones[i-1]+dp[i-1][j-stones[i-1]]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }

        int grp1Sum=dp[n][W];
        int grp2Sum=totalSum-grp1Sum;
        return abs(grp1Sum-grp2Sum);
        
    }
};