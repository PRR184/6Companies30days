#include <iostream>
// #include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;
typedef long double ld;

#define mod 1000000007
#define ma(x,y) make_pair(x,y)

// Time:-O(Nlog10) ~ O(N),space:O(10)

vector<int> solve(int arr[],int n){
	vector<int>ans;
	priority_queue<int,vector<int>,greater<int>>pq;

	for(int i=0;i<n;i++){
		pq.push(arr[i]);
		if(pq.size()>10)
			pq.pop();
	}
	while(!pq.empty()){
		ans.push_back(pq.top());
		pq.pop();
	}
	return ans;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
		vector<int>ans=solve(arr,n);
		cout<<"Max 10 values"<<"\n";
		for(auto x:ans){
			cout<<x<<" ";
		}
	}
											
	return 0;		
}