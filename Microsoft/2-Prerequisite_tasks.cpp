// Problem:-https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1/

// time:O(N+P),space:O(N+P)
class Solution {
    void bfs(int V,vector<int> adj[],int start,int &count,vector<int> &visited,vector<int> &inorder){
        //calculating inorder
        queue<int>q;
        for(int i=start;i<V;i++){
            if(visited[i]==0 && inorder[i]==0){
                q.push(i);
                visited[i]=1;
            }
        }
        while(!q.empty()){
            int vertex=q.front();
            q.pop();
            count++;
            for(auto x:adj[vertex]){
                if(!visited[x]){
                    inorder[x]--;
                    if(!inorder[x]){
                        q.push(x);
                        visited[x]=1;
                    }
                }
            }
        }
    }
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<int>adj[N];
	    vector<int>indegree(N,0),visited(N,0);
	    for(auto p:prerequisites){
	        adj[p.second].push_back(p.first);
	        indegree[p.first]++;
	    }
        int countp=0,countc=0;
	    for(int i=0;i<N;i++){
	        if(!visited[i]){
	            bfs(N,adj,i,countc,visited,indegree);
	            if(countc==countp)
	                return false;
	            countp=countc;
	        }
	    }
	    if(countp==N)
	        return true;
	    return false;
	}
};