    // Problem:-https://practice.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter1322/1/
    
    // Time:O(M),space:O(M)
    //Recusrion absed memoisation.
    long long solve(long long m,vector<vector<long long>> &dp,int flag){
        if(m<0)
            return 0;
        if(m==0)
            return 1;
        if(dp[flag][m]!=-1)
            return dp[flag][m];
        long long ans=0;
        if(!flag)
            ans+=solve(m-1,dp,flag);
        if(m%2==0){
            int flag1=1;
            ans+=solve(m-2,dp,flag1);
        }
        return dp[flag][m]=ans;
    }
    public:
    //Function to count number of ways to reach the nth stair 
    //when order does not matter.
    long long countWays(int m)
    {
        // your code here
        vector<vector<long long>>dp(2,vector<long long>(m+1,-1));
        return solve(m,dp,0);
    }