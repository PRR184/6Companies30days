
//Note:- Taking care of overflow is important, so divide by 2 after n*(n+1) is important.
long long squaresInChessBoard(long long N) {
        // code here
        long long ans=N;
        ans*=(N+1)/2;
        ans*=(2*N+1);
        ans/=3;
        return ans;
}