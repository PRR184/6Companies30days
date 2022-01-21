// Problem:-https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1/#

// Most Optimal Solution:- Time:O(N),space:O(1)
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
    
        int *ans = new int(2);
        int xor1=arr[0]^1;
        for(int i=1;i<n;i++){
            xor1^=arr[i];
            xor1^=(i+1);
        }
        int checkbit = xor1&(~(xor1-1));
        int x=0,y=0;
        for(int i=0;i<n;i++){
            if(arr[i]&checkbit){
                x^=arr[i];
            }else{
                y^=arr[i];
            }
        }
        for(int i=1;i<=n;i++){
            if(i&checkbit){
                x^=i;
            }else{
                y^=i;
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i]==x){
                ans[0]=x;
                ans[1]=y;
                break;
            }
            else if(arr[i]==y){
                ans[0]=y;
                ans[1]=x;
                break;
            }
        }
        return ans;

    }
};