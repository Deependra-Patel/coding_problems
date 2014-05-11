#include <iostream>
using namespace std;
void calc(int &a, int &b, int &d, int n, int m)
{
	int a1, b1, d1;
	if(n==1)
	{
		a=b=1;
		d=0;
	}
	else 
	{
		calc(a1,b1,d1,n/2, m);
		a=a1*a1+b1*b1;
		b=a1*b1+b1*d1;
		d=b1*b1+d1*d1;
		if(n%2!=0)
		{
			int tempb=b;
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
	}
}
int main()
{
	while(true)
	{
		int n, a, b, d;
		cin>>n;
		calc(a,b,d,n,10);
		cout<<d<<endl<<endl;
		
	}
}
