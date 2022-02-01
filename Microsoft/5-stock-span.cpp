
//Time:O(N),space:O(N)
class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       
       vector<int>nge(n);
       //Next Greater ELement on Left.
       stack<pair<int,int>>s;
       for(int i=0;i<n;i++){
           while(!s.empty() and s.top().first<=price[i])
                s.pop();
            if(s.empty())
                nge[i]=-1;
            else
                nge[i]=s.top().second;
            s.push({price[i],i});
       }
       vector<int>ans(n);
       for(int i=0;i<n;i++){
           ans[i]=i-nge[i];
       }
       return ans;
    }
};