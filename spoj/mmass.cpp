#include <iostream>
#include <cmath>
#include <string>
using namespace std
int calc(string s,int begin,int end)
{
	for(int i=begin+1;i<end;i++)
		{
			if(s[i]==)
		}
	}
	else if(s[index]==')')
	{
		
	}
}
int main()
{
	int sum=0,counter1=0,counter2=0;
	string str;
	int index-open[100],index-close[100];
	for(int i=0;i<100;i++)
	{
		index-open[i]=-1;
		index-close[i]=-1;
	}
		cin>>str;
	for(int i=0;i<str.length();i++)
	{
			if(str[i]=='(')
			{
			index-open[counter1]=i;
			counter1++;
		}
			else
			if(str[i]==')')
			{
			index-close[counter2]=i;
			counter2++;
		}
	}
		
}
