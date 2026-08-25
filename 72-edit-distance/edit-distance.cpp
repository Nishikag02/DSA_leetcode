class Solution {
public:
    int minDistance(string word1, string word2) {

        int n=word1.size();
        int m=word2.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        //word1 is empty
        for(int j=1;j<=m;j++){
            dp[0][j]=j;
        }

        //word2 is empty
        for(int i=1;i<=n;i++){
            dp[i][0]=i;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    //min of insert delete replace
                    dp[i][j]=1 + min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]});
                }

            }
        }

        return dp[n][m];
        
    }
};