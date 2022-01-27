// Problem:-https://practice.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication1024/1/


//Recursion Based Memoisation.
// Time:-O(N^3),Spcae:O(N^2);

class Solution {
    
    // Cache
    map<string, pair<int, string>> dp;
    
  public:
    string matrixChainOrder(int A[], int n) {
        return matrixChainOrderUtil(A, 0, n - 1).second;
    }
    
    pair<int, string> matrixChainOrderUtil(int p[], int l, int r) {
        if(l + 1 == r) return {0, "" + string(1, l + 'A')};
        string key = to_string(l) + ";" + to_string(r);
        if(dp.count(key)) return dp[key];
        
        int currMin = INT_MAX;
        string minString;
        for(int k = l + 1; k < r; k++) {
            auto p1 = matrixChainOrderUtil(p, l, k), p2 = matrixChainOrderUtil(p, k, r);
            if(p1.first + p2.first + p[l] * p[k] * p[r] < currMin) {
                currMin = p1.first + p2.first + p[l] * p[k] * p[r];
                // Multiply te 2 strings
                minString = p1.second + p2.second;
            }
        }
        // Enclose them in brackets and return
        return dp[key] = {currMin, "(" + minString + ")"};
    }
};