// Problem:-https://practice.geeksforgeeks.org/problems/total-decoding-messages1235/1/#

//DP solved Using Memoisation,Tim:O(N),space:O(N)
//Tabulation method similar to fibonacci series.
class Solution {
    int mod = 1e9 + 7;
    int solve(int i,int n,vector<int>&dp,string &str){
        if(i==n)
            return 1;
        if(str[i]=='0')
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int val=str[i]-'0';
        int left=0;
        if(val>0)
            left=solve(i+1,n,dp,str);
        if(i!=n-1){
            
            val=val*10+(str[i+1]-'0');
            if(val<27 and val>0){
                // cout<<val<<"\n";
                return dp[i]=(left%mod+solve(i+2,n,dp,str)%mod)%mod;
            }
            return dp[i]=left%mod;
        }
        return dp[i]=left%mod;
    }
	public:
		int CountWays(string str){
		    // Code here
		    int n=str.length();
		    vector<int>dp(n+1,-1);
		    return solve(0,n,dp,str);
		}

};