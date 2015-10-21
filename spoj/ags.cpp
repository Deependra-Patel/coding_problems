#include <iostream>
using namespace std;
long long mod;

long long mpow(long long r, long long n){
	if(n==0)
		return 1;
	long long temp = mpow(r, n/2);
	temp = (temp*temp)%mod;
	if(n%2!=0)
		temp= (temp*r)%mod;
	return temp;
}

long long calcSum(long long n, long long r){
	if(n==0)
		return 0;
	long long ans;
	if(n&1){
		long long temp = calcSum(n/2, r);
		long long mul = mpow(r, n/2+1);
		ans = (temp + temp*mul + mul)%mod;		
	}
	else {
		long long temp = calcSum(n/2, r);
		long long mul = mpow(r, n/2);
		ans = (temp + temp*mul)%mod;
	}
	//	cout<<n<<" "<<ans<<endl;
	return ans;		
}

int main(){
	int ntest;
	cin>>ntest;
	while(ntest--){
		long long a, d, r, n;
		cin>>a>>d>>r>>n>>mod;
		long long ans;
		ans = calcSum((n-1)/2, r);
		//cout<<ans;
		ans = (ans*d)%mod;
		//cout<<ans;
		ans = (ans + a*mpow(r, (n-1)/2))%mod;
		if(n%2!=1)
			ans = (ans+d)%mod;		
		cout<<ans<<endl;
	}
}
