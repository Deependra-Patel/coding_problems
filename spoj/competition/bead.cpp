#include <iostream>
#include <string>
using namespace std;
bool compare(string s,int i, int j)
{
	int l=s.length();
	int temp=0;
	bool igj=false;
	while(temp!=l)
	{
		if(s[i]>s[j])
		{
			igj=true;
			break;
		}
		else 
		if(s[i]<s[j])
		{
			igj=false;
			break;
		}
		else
		{	
			i++;
			j++;
			if(i==l)
			i=0;
			if(j==l)
			j=0;
		}
		temp++;
	}
	return igj;
}

int main()
{
	int ntest;
	cin>>ntest;
	for(int j=0;j<ntest;j++){
	string s;
	cin>>s;
	int l=s.length();
	int min=0;
	for(int i=1;i<l;i++)
	{
		if(compare(s, min, i))
		min=i;
	}
	cout<<min+1<<endl;
}
}
