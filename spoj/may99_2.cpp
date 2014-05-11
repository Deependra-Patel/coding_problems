#include <iostream>
#include <string>
using namespace std;
int main()
{
	long long no;
	cin>>no;
	char dic[5]={'m','a','n','k','u'};
	for(long long z=0;z<no;z++)
	{
		long long n;
		cin>>n;
		string s="";
		while(n!=0)
		{
			s=dic[(n-1)%5]+s;
			n=(n-1)/5;
		}
		cout<<s<<endl;
	}
}
