#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
long long divi=pow(10,9)+7;
int gcd(int a, int b)
{
	if (b==0)
		return a;
	else
		return gcd(b,a%b);
}
int main(){
	int ntest;
	cin>>ntest;
	while(ntest--){
		int n, m;
		cin>>n>>m;
		int * num=new int[n];
		int * denum=new int[n];
		for(int i=0; i<n; i++){
			num[i]=m+i;
		}
		for(int i=0; i<n; i++){
			denum[i]=i+1;
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(num[i]!=1 && denum[j]!=1){
					int fac=gcd(num[i], denum[j]);
					cout<<fac<<endl;
					num[i]/=fac;
					denum[j]/=fac;
				}
			}
		}
		long long ans=1;
		for(int i=0; i<n; i++){
			ans=(ans*num[i])%divi;
		}
		cout<<ans<<endl;
	}
}