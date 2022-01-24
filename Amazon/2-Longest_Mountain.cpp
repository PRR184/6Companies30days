// Problem:-https://leetcode.com/problems/longest-mountain-in-array/

// My Solution:- Time:O(N), Space:O(N)
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        if(n<3)
            return 0;
        vector<int> l(n,0),r(n,0);
        int i=1;
        while(i<n){
            int j=i;
            while(j<n and arr[j]>arr[j-1]){
                j++;
            }
            if(j!=i){
                l[j-1]=j-i+1;
                i=j;
            }
            else
                i++;
        }
        i=n-2;
        while(i>=0){
            int j=i;
            while(j>=0 and arr[j]>arr[j+1]){
                j--;
            }
            if(j!=i){
                r[j+1]=i-j+1;
                i=j;
            }
            else
                i--;
        }
        int ans=0;
        for(i=0;i<n;i++){
            if(l[i]==n or r[i]==n)
                return 0;
            if(l[i]!=0 and r[i]!=0)
                ans=max(ans,l[i]+r[i]-1);
        }
        return ans;
        
    }
};

// Optimisng Space:-Time:O(N),space:O(1)
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        int ans=0,i=0;
        while(i<n){
            int base=i;
            while(i+1<n and arr[i]<arr[i+1])
                i++;
            if(base==i){
                i++;
                continue;
            }
            int peak=i;
            while(i+1<n and arr[i]>arr[i+1])
                i++;
            if(peak==i){
                i++;
                continue;
            }
            ans=max(ans,i-base+1);
        }
        return ans;
        
    }
};