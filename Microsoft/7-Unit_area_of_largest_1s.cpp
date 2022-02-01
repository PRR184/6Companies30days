// Problem:-https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s-1587115620/1/#

// Time:O(N*M),space:O(N*M);
class Solution
{
    void dfs(vector<vector<int>>& grid,int i,int j,int n,int m,int &count){
        if(i<0 or i>=n or j<0 or j>=m or grid[i][j]!=1)
            return;
        grid[i][j]=0;
        count++;
        int x[8]={1,-1,0,0,1,1,-1,-1};
        int y[8]={0,0,1,-1,1,-1,1,-1};
        for(int t=0;t<8;t++){
            dfs(grid,i+x[t],j+y[t],n,m,count);
        }
    }
    public:
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int ans=0,n=grid.size(),m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    dfs(grid,i,j,n,m,count);
                    ans=max(ans,count);
                    count=0;
                }
            }
        }
        return ans;
    }
};