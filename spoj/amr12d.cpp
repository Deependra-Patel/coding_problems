#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	int n;
	cin>>n;
	int l;
	bool flag;
	for(int i=0;i<n;i++)
	{
		flag=true;
		cin>>s;
		l=s.length();
		for(int j=0;j<l/2;j++)
		{
			if(s[j]!=s[l-j-1])
			{
				flag=false;
				break;
			}
		}
		if(flag)
		cout<<"YES";
		else cout<<"NO";
		cout<<endl;
	}
}
