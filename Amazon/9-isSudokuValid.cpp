    //Time:O(N^2),space:O(N);
    int isValid(vector<vector<int>> mat){
        // code here
        //For Rows
        for(int i=0;i<9;i++){
            int hash[10]={0};
            
            for(int j=0;j<9;j++){
                if(mat[i][j]<0 or mat[i][j]>9)
                    return false;
                hash[mat[i][j]]++;
                if(mat[i][j]!=0 and hash[mat[i][j]]>1)
                    return false;
            }
        
        }
        //For Cols
        for(int i=0;i<9;i++){
            int hash[10]={0};
            
            for(int j=0;j<9;j++){
                if(mat[j][i]<0 or mat[j][i]>9)
                    return false;
                hash[mat[j][i]]++;
                if(mat[j][i]!=0 and hash[mat[j][i]]>1)
                    return false;
            }
        
        }
        //For 9 Boxes
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                int hash[10]={0};
                for(int k=i;k<i+3;k++){
                    for(int q=j;q<j+3;q++){
                        hash[mat[k][q]]++;
                        if(mat[k][q]!=0 and hash[mat[k][q]]>1)
                            return false;                       
                    }
                }

            }
        
        }

        return true;
    }