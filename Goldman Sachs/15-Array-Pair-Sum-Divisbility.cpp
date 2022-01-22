// Problem:- https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1

//Using Hashing (like "2pair sum" problem which is not in sorted order!)
// Time:O(N),space:O(N)
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        if(nums.size()&1)
            return false;
        map<int,int>mp;
        for(auto x:nums)
            mp[x%k]++;
        for(auto x:nums){
            int rem=x%k;
            if(mp[rem]==0)
                continue;
            mp[rem]--;
            if(mp.find((k-rem)%k)!=mp.end() and mp[(k-rem)%k]!=0){
                mp[(k-rem)%k]--;
            }
            else
                return false;
        }
        return true;
    }
};