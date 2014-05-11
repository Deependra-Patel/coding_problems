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
	long long* arr=new long long[1000000010];
	for(long long i=0;i<=1000000009;i++)
	arr[i]=-1;
	arr[0]=0;
	arr[1]=1;
	int ninput;
	cin>>ninput;
	for(int i=0;i<ninput;i++)
	{
		int N,M;
		long long sum=0,a,b,d;
		cin>>N>>M;
		for(int j=N;j<=M;j++)
		{
			calc(a,b,d,j,1000000007,arr);
			sum=sum+d;
			if(sum>=1000000007)
			sum%=1000000007;
		}
		cout<<sum<<endl;
	}
}

