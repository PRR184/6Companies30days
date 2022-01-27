// Time:O(N^2)
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int r=grid.size(),c=grid[0].size();
        //Initialisation
        queue<pair<int,int>>q;  //store x,y coorderinates.
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==2)
                    q.push({i,j});
            }
        }
        //dong bfs
        int timer=0;
        while(!q.empty()){
            int n=q.size();
            bool flag=false;
            while(n--){
                int x=q.front().first,y=q.front().second;
                q.pop();
                
                // top
                if(x-1 >=0 && grid[x-1][y]==1){
                    q.push({x-1,y});
                    grid[x-1][y]=2;
                    flag=true;
                }
                //down
                if(x+1 < r && grid[x+1][y]==1){
                    q.push({x+1,y});
                    grid[x+1][y]=2;
                    flag=true;
                }
                //left
                if(y-1 >=0 && grid[x][y-1]==1){
                    q.push({x,y-1});
                    grid[x][y-1]=2;
                    flag=true;
                }
                //right
                if(y+1 < c && grid[x][y+1]==1){
                    q.push({x,y+1});
                    grid[x][y+1]=2;
                    flag=true;
                }
            }
            if(flag)
                timer++;
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1)
                    return -1;
            }
        }
        return timer;
    }
};