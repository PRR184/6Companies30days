
// Time:O(V+E),space:O(V)
class Solution
{
    void dfs(vector<int> adj[],vector<int> &visited,int x){
        visited[x]=1;
        
        for(auto node:adj[x]){
            if(!visited[node])
                dfs(adj,visited,node);
        }
    }
	public:
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        vector<int>visited(V,0);
        int count1=0;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                count1++;
                dfs(adj,visited,i);
            }
        }
        
        vector<int>temp1,temp2;
        for(auto x:adj[c]){
            if(x!=d)
                temp1.push_back(x);
        }
        adj[c]=temp1;
        for(auto x:adj[d]){
            if(x!=c)
                temp2.push_back(x);
        }
        adj[d]=temp2;
        
        for(int i=0;i<V;i++)
            visited[i]=0;
        int count2=0;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                count2++;
                dfs(adj,visited,i);
            }
        }
        if(count1==count2)
            return 0;
        return 1;
    }
};