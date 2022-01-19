// Problem:-https://practice.geeksforgeeks.org/problems/overlapping-rectangles1924/1/#
class Solution {
  public:
    int doOverlap(int L1[], int R1[], int L2[], int R2[]) {
        // code here
        
        //Leftside of 1 is greater than Right side of 2
        //Leftside of 2 is greater than Leftside of 1
        if(L1[0] > R2[0] or L2[0] > R1[0]) 
            return 0;
        //Top of 1 is less than Bottom of 2
        //Bottom of 1 is greater than Top of 2
        if(L1[1] < R2[1] or R1[1] > L2[1])
            return 0;
        return 1;
    }
};