//Problem:-https://leetcode.com/problems/minimum-size-subarray-sum/

//Using 2-pointers approach ,Optimal.
//Time:O(N),space:O(1)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if(target==1)
            return 1;
        int left=0,right=0,n=nums.size();
        long long sum=0;
        int ans=INT_MAX;
        while(right<n){
            if(ans==1 or nums[right]==target)
                return 1;
            sum+=nums[right];
            if(sum>=target){
                ans=min(right-left+1,ans);
                sum-=nums[left];
                left++;
                while(left<=right and sum>=target){
                    ans=min(right-left+1,ans);
                    sum-=nums[left];
                    left++;
                }
            }
            right++;
        }
        return ans==INT_MAX?0:ans;
    }
};