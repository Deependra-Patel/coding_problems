#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
long long calc(long  long x)
{
	if(x==0 || x==2 ||x==1 ||x==3)
	return x;
	else
	{
	long long z=calc(x/2) + calc(x/3) +calc(x/4);
	if(z>x)
	return z;
	else return x;
	}
}
int main()
{
	int n;
	long long x;
	cin>>n;
	for(int z=0;z<n;z++)
	{
		cin>>x;
		cout<<calc(x)<<endl;
	}
}