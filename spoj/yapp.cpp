#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define mod 1000000007

long long pow(int i){
	if(i==0)
		return 1;
	long long temp = pow(i/2);
	temp = (temp*temp)%mod;
	
	if(i%2 != 0){
		temp = (2*temp)%mod;
	}
	return temp;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		long long ans = 1;
		//for(int i=0; i<n-1; i++){
		//	ans = (ans<<1)%mod;
		//}
		cout<<pow(n-1)<<endl;
	}
}
