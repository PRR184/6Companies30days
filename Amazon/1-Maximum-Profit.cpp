// Problem:-https://practice.geeksforgeeks.org/problems/maximum-profit4657/1

//Time:O(N*K),space:O(N*K)
class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
        // code here
        if(K>N/2){
            int maxProfit = 0;
            for(int i=1;i<N;i++){
                if(A[i]>A[i-1])
                    maxProfit+=A[i]-A[i-1];
            }
            return maxProfit;
        }
        int dp[K+1][N];
        for(int i=0;i<N;i++)
            dp[0][i]=0;
        for(int i=1;i<=K;i++){
            int maxDiff=INT_MIN;
            for(int j=0;j<N;j++){
                if(j==0){
                    dp[i][j]=0;
                    maxDiff=dp[i-1][j]-A[j];
                }else{
                    dp[i][j]=max(dp[i][j-1],A[j]+maxDiff);
                    maxDiff=max(maxDiff,dp[i-1][j]-A[j]);
                }
            }
        }
        return dp[K][N-1];
    }
};