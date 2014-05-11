#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	string s1, s2;
	cin>>s1;
	cin>>s2;
	int i;
	while(s1!="*")
	{
		long long p,l1=s1.length(),l2=s2.length();
			for(p=0;p<l1;p++)
			{
				if(s1[p]!='0')
				break;
			}
			if(p==l1)
			s1="";
			else
			s1=s1.substr(p);
			l1=s1.length();
			for(p=0;p<l2;p++)
			{
				if(s2[p]!='0')
				break;
			}
			if(p==l2)
			s2="";
			else
			s2=s2.substr(p);
			l2=s2.length();
			if(l1==0 && l2==0)
			cout<<"=";
			else if(l1==0)
			cout<<"<";
			else if(l2==0)
			cout<<">";
			else if(l1>l2)
			cout<<">";
			else if(l2>l1)
			cout<<"<";
			else
			{
		for(i=0;i<l1;i++)
		{
			if(s1[i]>s2[i])
			{
				cout<<">";
				break;
			}
			else if(s1[i]<s2[i])
			{
				cout<<"<";
				break;
			}
		}
		if(i==l1)
		cout<<"=";
	}
		cout<<endl;
		cin>>s1;
		cin>>s2;
	}
}
