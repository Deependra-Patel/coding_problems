#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int main()
{
	long long n,temp,size,ahead;
	int len,comf,comb;
	string str,str_rev;
	cin>>n;
	for(long long z=0;z<n;i++)
	{
		cin>>str;
		len=str.length();
		str_rev=str.reverse();
		comf=0,comb=0;
		for(int i=1;i<len;i++)
		{
			if(str[i]==str[0])
			comf++;
			else break;
		}
		for(int i=len-2;i>=0;i--)
		{
			if(str[i]==str[len-1])
			comb++;
			else break;
		}
		
		cout<<endl;
	}
}
