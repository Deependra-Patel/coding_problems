#include <iostream>
using namespace std;
#include <math.h>

long long expp(long long  a, long long b,long long n)
{
	if(b==0)
	return 1;
	long long temp=expp(a,b/2,n);
	if(b%2==0)
		return (temp%n*temp%n)%n;
	else
	if(b%2==1)
		return (((temp%n*temp%n)%n)*(a%n))%n;
}

int main()
{
	long long  n,l,ans,mod=(pow(10,9)+7);
	while(true)
	{	ans=0;
		cin>>n;
		cin>>l;
		if(n==0 && l==0)
		break;
		for(int i=0;i<l;i++)
		ans=(ans%mod+expp(n,i+1,mod))%mod;
		cout<<ans<<endl;
	}
}
