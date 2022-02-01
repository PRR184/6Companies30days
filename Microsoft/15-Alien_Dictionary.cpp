//Practice:-https://practice.geeksforgeeks.org/problems/alien-dictionary/1/

//Time:O(N * |S| + K),space:O(K);
class Solution{
void topoSort(vector<int>adj[],int start,vector<bool>&visited,string &ans){
        visited[start]=true;
        for(auto x:adj[start]){
            if(!visited[x])
                topoSort(adj,x,visited,ans);
        }
        char c = start+'a';
        ans=c+ans;
    }
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int>adj[K];
        for(int i=0;i<N-1;i++){
            string s1=dict[i],s2=dict[i+1];
            int n=min(s1.length(),s2.length());
            for(int j=0;j<n;j++){
                if(s1[j]!=s2[j]){
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
        }
        //After this step my graph is finished;
        string ans="";
        vector<bool>visited(K,false);
        for(int i=0;i<K;i++){
            if(!visited[i])
                topoSort(adj,i,visited,ans);
        }
        return ans;
    }
};