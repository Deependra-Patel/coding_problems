#include <iostream>
#include <algorithm>
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
	int* arr=new int[100000001];
	int a=0, b=1, c, sum=0;
	arr[0]=-500000;
	arr[1]=-499999;
	c=a+b;
	int temp;
	temp=b;
	b=c;
	a=temp;
	for(int i=2;i<=100000000;i++){
		c=a+b;
		arr[i]=c%1000007-500000;
		temp=b;
		b=c;
		a=temp;
	}
	int len=0;
	for(int i=0; i<100000000; i++){
		sum=arr[i];
		for(int j=i+1; j<100000000; j++){
			sum+=arr[j];
			if(sum>=0)
			len=max(len, j-i+1);
		}
	}
	cout<<len;
		
	//}
}

