//Problem:-https://practice.geeksforgeeks.org/problems/count-the-subarrays-having-product-less-than-k1708/1/

//BruteForce:- Time:O(N^2)
class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int count=0;
        for(int i=0;i<n;i++){
            long long product=1;
            for(int j=i;j<n;j++){
                product = product*a[j];
                if(product<k)
                    count++;
                else
                    break;
            }
        }
        return count;
    }
};

//Optimal:- O(N) Using Sliding Window Concept. 
class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int left=0,right=0;
        int result=0;
        long long product=1;
        while(right<n){
            product*=a[right];
            while(product>=k){
                product/=a[left];
                left++;
            }
            //To understand result step, dry run for {1,2,3,4,5} , k=15;
            result += (right-left)+1;
            right++;
        }
        return result;
    }
};