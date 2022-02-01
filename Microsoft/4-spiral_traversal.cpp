// Problem:-https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1/
// Time:O(r*c),space:O(1)

class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        vector<int>ans;
        int l=0,ri=c-1,t=0,b=r-1;
        int sw=0;
        while(l<=ri and t<=b){
            switch(sw){
                case 0:
                    for(int i=l;i<=ri;i++){
                        ans.push_back(matrix[t][i]);
                    }
                    t++;
                    sw=1;
                    break;
                case 1:
                    for(int i=t;i<=b;i++){
                        ans.push_back(matrix[i][ri]);
                    }
                    ri--;
                    sw=2;
                    break;
                case 2:
                    for(int i=ri;i>=l;i--){
                        ans.push_back(matrix[b][i]);
                    }
                    b--;
                    sw=3;
                    break;
                case 3:
                    for(int i=b;i>=t;i--){
                        ans.push_back(matrix[i][l]);
                    }
                    l++;
                    sw=0;
                    break;
            }
        }
        return ans;
    }
};