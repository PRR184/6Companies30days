// Problem:-https://practice.geeksforgeeks.org/problems/minimum-number-of-steps-to-reach-a-given-number5234/1/

//Time:O(N),space:O(1)
class Solution{
public:
    int minSteps(int D){
        // code here
        int total=0,steps=0;
        while(D>total){
            steps++;
            total+=steps;
        }
        if(total==D)
            return steps;
        int diff=total-D;
        if(diff&1){
            if((steps+1)&1)
                return steps+1;
            return steps+2;
        }
        return steps;
    }
};