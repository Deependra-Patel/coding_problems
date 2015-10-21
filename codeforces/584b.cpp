#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;
int main(){
	int n;
	cin>>n;
	long long mod = 1000000007;
	long long ans = 1;
	for(int i=0; i<n; i++){
		ans = (ans*27)%mod;
	}
	//cout<<ans;
	long long ans2 =1;
	for(int i=0; i<n; i++){
		ans2 = (ans2*7)%mod;
	}
	//cout<<ans2;
	ans = (ans-ans2+mod)%mod;
	cout<<ans<<endl;
}
