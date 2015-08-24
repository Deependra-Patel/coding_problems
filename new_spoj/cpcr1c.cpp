#include <iostream>
#include <math.h>
using namespace std;

int numDigits(int x){
	int count = 0;
	while(x>0){
		count++;
		x/=10;
	}
	return count;
}
long long* dp;
long long sumFrom1(int x){
	if(x<1000000 && dp[x]!=-1)
		return dp[x];
	if(x==0)
		return 0;
	int nd = numDigits(x);
	int t = pow(10, nd-1);
	long long ans = (x/t)*(x%t+1)+sumFrom1(x%t) + sumFrom1(x-x%t-1
);
	if(x<1000000)
		dp[x]= ans;
	return ans;
}
int main(){
	int a, b;
	cin>>a>>b;
	dp=new long long[1000000];
	for(int i=0; i<1000000; i++)
		dp[i] = -1;
	while(a!=-1){
		long long sum = sumFrom1(b) - sumFrom1(a-1);
		cout<<sum<<endl;
		cin>>a>>b;
	}
}
