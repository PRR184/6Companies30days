// Probelm:-https://practice.geeksforgeeks.org/problems/rotate-by-90-degree0356/1/

// Time:O(N*2),pace:O(1);

void rotate(vector<vector<int> >& matrix)
{
    // Your code goes here
    
    int n=matrix.size();
    //step-1:Performing Transpose.
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    
    //step-2 to rearrange the rows.
    for(int i=0;i<n/2;i++){
        for(int j=0;j<n;j++){
            swap(matrix[i][j],matrix[n-i-1][j]);
        }
    }
}