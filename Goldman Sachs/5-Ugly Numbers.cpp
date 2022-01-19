	//problem:-https://practice.geeksforgeeks.org/problems/ugly-numbers2254/1/#
    
    //Brute Force:- Using isUgly() until nth number, O(nlogn)<Time<O(n^2)
    bool isUgly(int n) {
        if(n<=0)
            return false;
        while(n!=1){
            if(n%2==0)
                n/=2;
            else if(n%3==0)
                n/=3;
            else if(n%5==0)
                n/=5;
            else
                return false;
        }
        return true;
    }

    //Optimal:- DP(Thinking of generating new ugly numbers from old ugy numbers).
    //Time:O(n),space:O(n).
    ull getNthUglyNo(int n) {
	    // code here
	    long long i2=0,i3=0,i5=0;
	    long long n2=2,n3=3,n5=5;
	    long long ugly[n];
	    ugly[0]=1;
	    
	    int i=1;
	    while(i<n){
	        ugly[i]=min(n2,min(n3,n5));
	        if(ugly[i]==n2){
	            i2++;
	            n2=ugly[i2]*2;
	        }
	        if(ugly[i]==n3){
	            i3++;
	            n3=ugly[i3]*3;
	        }
	        if(ugly[i]==n5){
	            i5++;
	            n5=ugly[i5]*5;
	        }
	        i++;
	    }
	    return ugly[n-1];
	}