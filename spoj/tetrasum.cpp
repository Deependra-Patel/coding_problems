#include <iostream>
using namespace std;
#define mod 1000000007
int main(){
	long long * arr=new long long[100000]
	arr[0]=arr[1]=arr[2]=0;
	arr[3]=1;
	arr[4]=1;
	for(int i=5; i<100000; i++){
		arr[i]=(2*arr[i-1]-arr[i-5])%mod;
	}
	int ntest;
	cin>>ntest;
	while(ntest--){
		int m, n;
		long long ans=0;
		cin>>m>>n;
		m=m-1;
		n=n-1;
		if(m<100000){
			for(int i=m; i<=n; i++){

			}
		}
	}
}