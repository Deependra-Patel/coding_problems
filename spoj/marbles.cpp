#include <iostream>
using namespace std;
long long nCr(int n, int r){
	if(r==0 || (n==r))
	return 1;
	else return (nCr(n-1,r)+nCr(n-1, r-1));
}
int main(){
	int ntest;
	cin>>ntest;
	for(int z=0; z<ntest; z++){
		long long n,k;
		cin>>n>>k;
		if(n==k)
		cout<<1<<endl;
		else
		cout<<nCr(n-1, k)<<endl;
	}
}
