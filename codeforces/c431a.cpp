#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
int val=pow(10,9)+7;
long long compute(int n, int k, int d, int* dp0,int* dp1){
	if(n==0 && d==0)
		return 1;
	else if(n<=0)
		return 0;
	if(k<d)
		return 0;

	if(d==0 && (dp0[n-1]!=-1)){
		return dp0[n-1];
	}
	else if(d!=0 && (dp1[n-1]!=-1))
		return dp1[n-1];

	long long ans=0;
	if(d==0){
		for(int i=1; i<=k; i++)
			ans=(ans+compute(n-i, k, d, dp0, dp1))%val;
	}
	else {
		for(int i=1; i<=k; i++){
			if(i>=d)
				ans=(ans+compute(n-i, k, 0, dp0, dp1))%val;
			else 
				ans=(ans+compute(n-i, k, d, dp0, dp1))%val;				
		}
	}
	if(d==0)
		dp0[n-1]=ans;
	else dp1[n-1]=ans;
	return ans;
}
int main(){
	int n, k, d;
	cin>>n>>k>>d;
	int* dp0=new int[n];
	int* dp1=new int[n];
	for(int i=0; i<n; i++){
		dp0[i]=-1;
		dp1[i]=-1;
	}
	cout<<compute(n, k, d, dp0, dp1)<<endl;
/*	for(int i=0; i<n; i++){
		cout<<dp0[i]<<endl;
	}*/
}
