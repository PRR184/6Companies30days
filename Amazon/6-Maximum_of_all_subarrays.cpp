
//Time:O(N), Space:O(K)
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        vector<int> ans;
        deque<pair<int,int>> dq;
        for(int i=0;i<n;i++){
            while(!dq.empty() and dq.front().second<=(i-k))
                dq.pop_front();
            while(!dq.empty() and dq.back().first<=arr[i])
                dq.pop_back();
            dq.push_back({arr[i],i});
            if(i>=k-1)
                ans.push_back(dq.front().first);
        }
        return ans;
    }
};