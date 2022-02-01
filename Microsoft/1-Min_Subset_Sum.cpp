// Problem:-https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1/

// Time:O(N*sum),space:O(N*sum);

class Solution{
    vector<bool> isSubsetSum(int N, int arr[], int sum){
        // code here
        bool dp[N+1][sum+1];
        for(int i=0;i<=N;i++){
            for(int w=0;w<=sum;w++){
                if(w==0)
                    dp[i][w]=true;
                else if(i==0)
                    dp[i][w]=false;
                else if(arr[i-1]<=w){
                    dp[i][w]=dp[i-1][w]||dp[i-1][w-arr[i-1]];
                }
                else
                    dp[i][w]=dp[i-1][w];
            }
        }
        vector<bool>ans(sum+1);
        for(int i=0;i<=sum;i++)
            ans[i]=dp[N][i];
        return ans;
    }
  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
        int sum=0,minD=INT_MAX;
        for(int i=0;i<n;i++)
            sum+=arr[i];
        vector<bool>ans=isSubsetSum(n,arr,sum/2);
        for(int i=0;i<=sum/2;i++){
            if(ans[i])
                minD=min(minD,sum-2*i);
        }
        return minD;
	} 
};