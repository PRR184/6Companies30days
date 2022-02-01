
//Time:O(N^3),space:O(1);
class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        
        vector<vector<int>>ans;
        
        sort(arr.begin(),arr.end());
        int n=arr.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int sum=k-arr[i]-arr[j];
                int left=j+1,right=n-1;
                
                while(left<right){
                    if(arr[left]+arr[right]<sum)
                        left++;
                    else if(arr[left]+arr[right]>sum)
                        right--;
                    else{
                        vector<int>temp(4);
                        temp[0]=arr[i];
                        temp[1]=arr[j];
                        temp[2]=arr[left];
                        temp[3]=arr[right];
                        
                        //Removing duplicates.
                        while(left+1<right and arr[left+1]==temp[2])
                            left++;
                        while(left<right-1 and arr[right-1]==temp[3])
                            right--;
                        left++;
                        right--;
                        ans.push_back(temp);    
                    }    
                }
                
                //Removing Duplicates.
                while(j+1<n and arr[j+1]==arr[j])
                    j++;
            }
            //Removing Duplicates.
            while(i+1<n and arr[i+1]==arr[i])
                i++;
        }
        return ans;
    }
};