#include <iostream>
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
	long long arr[]={9,99,999,9999,99999,999999,9999999,99999999,999999999, 9999999999};
	for(int i=0; i<t; i++){
		long long l,r;
		scanf("%d %d", &l, &r);
		long long ans=0;
		int nl=nd(l);
		int nr=nd(r);
		long long ul=arr[nl-1];
		long long ur=arr[nr-2];
		for(long long val=l; val<)
