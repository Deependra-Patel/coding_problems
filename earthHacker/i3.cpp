#include <iostream>
using namespace std;
long long ans(long long* dp, long long  n, long long ind, bool last){
	if(ind >= n)
		return 1;
	if(ind == n-1){
		if(last)
			return 1;
		else return 2;
	}
	if(dp[ind]!=-1)
		return dp[ind];
	long long x;
	if(last)
		x = ans(dp, n, ind+1, false);
	else x = ans(dp, n, ind+1, false)+ans(dp, n, ind+2, false);
	dp[ind] = x;
	return x;
}

int main(){
	int tests;
	cin>>tests;
	for(int i=0; i<tests; i++){
		int n;
		cin>>n;
		long long * dp = new long long[n];
		for(int j=0; j<n; j++){
			dp[j] = -1;
		}
		cout<<ans(dp, n, 0, false)<<endl;
	}
}
