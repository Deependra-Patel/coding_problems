#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>
#include <vector> 
#include <stdlib.h> 
#include <iomanip>
#include <algorithm>
using namespace std;
long long gcd(long long a, long long b)
{
	if (b==0)
		return a;
	else
		return gcd(b,a%b);
}
int main(){
	long long ntest;
	cin>>ntest;
	while(ntest--){
		long long n, m;
		cin>>n>>m;
		long long neven=n/2;
		long long nodd=n-neven;
		long long meven=m/2;
		long long modd=m-meven;
		long long g=gcd(n*m, nodd*meven+neven*modd);
		cout<<(nodd*meven+neven*modd)/g<<"/"<<(n*m)/g<<endl;
	}
}