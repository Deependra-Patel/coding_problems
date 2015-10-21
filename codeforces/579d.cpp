#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
long long* arr, *afterOr;
int* powi;
long long** dp;
int n;
long long calc(int k, int x, int i){
	//	cout<<i<<endl;
	if(i>=n)
		return 0;
	else if(k<=0)
		return afterOr[i];
	else {
		if(dp[i][k-1]!=-1){
			//cout<<"dd";
			return dp[i][k-1];
		}
			
		long long ans = 0;
		for(int j=0; j<=k; j++){
			long long temp =  calc(k-j, x, i+1);
			for(int z=0; z<j+1; z++){
				ans = max(ans, temp|arr[i]*powi[z]);
			}
		}
		dp[i][k-1] = ans;
		return ans;
	}
}

int main(){
	int k, x;
	cin>>n>>k>>x;
	arr = new long long[n]; 
	afterOr = new long long[n];
	powi = new int[k+1];
	dp = new long long*[n];
	for(int i=0; i<n;  i++){
		cin>>arr[i];
		dp[i] = new long long[k];
		for(int j=0; j<k; j++){
			dp[i][j] = -1;
		}
	}
	afterOr[n-1] = arr[n-1];
	for(int i=n-2; i>=0; i--){
		afterOr[i] = afterOr[i+1]|arr[i];
	}
	powi[0] = 1;
	for(int i=1; i<k+1; i++){
		powi[i] = powi[i-1]*x;
	}
	/*
	sort(arr, arr+n);
	long long ans = arr[n-1];
	for(int i=0; i<k; i++)
		ans *= x;
	for(int i=n-2; i>=0; i--){
		ans = ans | arr[i];
	}
	cout<<ans<<endl;
	*/
	cout<<calc(k, x, 0)<<endl;
}
