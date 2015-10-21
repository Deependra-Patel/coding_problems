#include <iostream>
#include <stdio.h>
using namespace std;
long long calc(long long  n, long long k){
	//	cout<<n<<" "<<k<<endl;
	if(n == 1)
		return 0;
	if(k<=n/2){
		return calc(n/2, k);
	}
	else if(k == n/2+1){
		return 0;
	}
	else return !calc(n/2, n-k+1);
}

int main(){
	int ntest;
	cin>>ntest;
	for(int i=1; i<=ntest; i++){
		long long x;
		cin>>x;
		long long up = 1;
		long long temp = x;
		while((temp=temp>>1)!=0){
			//temp = temp>>1;
			up = up<<1 | 1;
		}
		long long ans = calc(up, x);
		//	cout<<up<<endl;
		//cout<<calc(up, x)<<endl;
		printf("Case #%d: %lld\n", i, ans);
	}
}
