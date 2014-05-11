#include <iostream>
using namespace std;
int main()
{
	long long n;
	long long x,y;
	cin>>n;
	for(long long z=0;z<n;z++)
	{
		cin>>x;
		cin>>y;
		if(x==y)
		{
			if(x%2==0)
			cout<<2*x;
			else
			cout<<2*x-1;
		}
		else if(y==x-2)
		{
			if(x%2!=0)
			cout<<x+y-1;
			else
			cout<<x+y;
		}
		else cout<<"No Number";
		cout<<endl;
	}
}
