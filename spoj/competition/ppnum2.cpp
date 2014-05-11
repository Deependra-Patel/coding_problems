#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;
int nd(long long n){
	long long d=1, i=0;
	while(d<=n){
		d*=10;
		i++;
	}
	return i;
}
int main(){
	int t;
	scanf("%d",&t);
	for(int i=0; i<t; i++){
		long long l,r;
		scanf("%ld %ld", &l, &r);;
		long long ans=0;
		int nl=nd(l);
		//cout<<nl;
		long long barrier=pow(10,nl);
		for(long long val=l; val<=r; val++){
			ans+=val*nl;
			if(ans>=1000000007)
			ans%=1000000007;
			if(val==barrier-1){
				nl++;
				barrier*=10;
			}
			//cout<<ans<<endl;
		}
		printf("%ld \n", ans);
	}
}
			
			
