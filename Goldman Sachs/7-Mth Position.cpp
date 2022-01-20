// problem:-https://practice.geeksforgeeks.org/problems/find-the-position-of-m-th-item1723/1/
class Solution {
  public:
    int findPosition(int N , int M , int K) {
        // code here
        return ((K+M-2)%N+1);
    }
};