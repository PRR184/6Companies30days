// Problem:-https://practice.geeksforgeeks.org/problems/possible-words-from-phone-digits-1587115620/1/

// Time:O(4^N * N),space:O(N);
class Solution
{

    map<int,string>adj;   
    
    void solve(int i,int a[], int N,vector<string> &ans,string temp){
        if(i>=N){
            ans.push_back(temp);
            return;
        }
        for(auto c:adj[a[i]]){
            solve(i+1,a,N,ans,temp+c);
        }
    }
    public:
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        adj[2]="abc";
        adj[3]="def";
        adj[4]="ghi";
        adj[5]="jkl";
        adj[6]="mno";
        adj[7]="pqrs";
        adj[8]="tuv";
        adj[9]="wxyz";
        
        vector<string>ans;
        string temp;
        solve(0,a,N,ans,temp);
        return ans;
    }
};