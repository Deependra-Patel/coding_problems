#include <iostream>
using namespace std;
int main(){
	int ntest;
	cin>>ntest;
	while(ntest--){
		long long a, d, r, n, mod;
		cin>>a>>d>>r>>n>>mod;
		long long ans;
		int x=n%2;
		n=n/2;
		long long last=1, rs=0;
		for(int i=1; i<n; i++){
			last=(last*r)%mod;
			rs=(rs+last)%mod;
		}
		last=(last*r)%mod;
		rs=(rs+last)%mod;
		ans = (last*a)%mod;
		if(x!=1)
		ans+=d;
		ans = (ans + rs*d)%mod;
	




		/*
		bool even = true;
		for(int i=2; i<=n; i++){
			if(even)
				ans=(ans+d)%mod;
			else 
				ans=(ans*r)%mod;
			even=!even;
		}*/
		cout<<ans<<endl;
	}
}
