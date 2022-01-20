// Problem:-https://practice.geeksforgeeks.org/problems/number-following-a-pattern3126/1#

// Time:O(N),space:O(1)
class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here
        int n=S.length();
        string ans="1";
        int lastI=0,lastN=1;
        for(int i=0;i<n;i++){
            if(S[i]=='I'){
                lastI=i+1;
                lastN=lastN+1;
                // cout<<(int)ans<<"\n";
                ans=ans+to_string(lastN);
            }else{
                lastN=lastN+1;
                ans=ans.substr(0,lastI)+to_string(lastN)+ans.substr(lastI);
            }
        }
        return ans;
    }
};