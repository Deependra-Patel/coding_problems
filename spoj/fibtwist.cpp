#include <iostream>
using namespace std;
void calc(long long &a, long long &b, long long &d, int n, int m, long  long *arr)
{
	long long a1, b1, d1;
	if(arr[n]!=-1)
	{
		d=arr[n];
		if((arr[n+2]!=-1)&& (arr[n+1]!=-1))
		{
			a=arr[n+2];
			b=arr[n+1];
		}
		else {
			calc(a1,b1,d1,n,m,arr);
			b=arr[n+1];
			a=arr[n+2];
		}
	}
	if(n==1)
	{
		a=b=1;
		d=0;
	}
	else 
	{
		calc(a1,b1,d1,n/2, m, arr);
		a=a1*a1+b1*b1;
		b=a1*b1+b1*d1;
		d=b1*b1+d1*d1;
		if(n%2!=0)
		{
			long long tempb=b;
			b=a;
			d=tempb;
			a=a+tempb;
		}
		if(a>=m)
		{
			a%=m;
			if(b>=m)
			{
				b%=m;
				if(d>=m)
				d%=m;
			}
		}
		arr[n]=d;
		arr[n+1]=b;
		arr[n+2]=a;
	}
}

int main()
{
	int ntest;
	cin>>ntest;
	for(int i=0;i<ntest;i++)
	{
		int nth, m;
		long long ans=1, last1=1, last2=0;
		cin>>nth>>m;
		
		cout<<endl;
	}
}
