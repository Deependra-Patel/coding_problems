#include <iostream>
using namespace std;
#include <string>
bool add1(int* first,int len)
{
	int carry=1,i;
	for(i=0;i<len;i++)
	{
		if((carry==1)&&(first[i]==9))
		{	first[i]=0;
			carry=1;
		}
		else
		{
			carry=0;
			first[i]++;
			break;
		}
	}
	if(carry==1)
	{
	first[i]=1;
	return true;}
	else{
	for(int i=0;i<len;i++)
	cout<<first[i]<<endl;
	return false;
}
}
int main()
{
	int n,l,half,mid;
	string s;
	bool found=false;
	int first[1000000],second[1000000];
	cin>>n;
	for(int z=0;z<n;z++)
	{
		cin>>s;
		l=s.length();
		int counter=0;
		if(l==1)
		cout<<s;
		else
		if(l%2!=0)
		{
			half=l/2;
			for(int i=0;i<half;i++)
			{
				first[i]=s[half-i-1]-'0';
				second[i]=s[half+i+1]-'0';
			}
			mid=s[half]-'0';
			while(true)
			{
				if(first[counter]>second[counter])
				break;
				else 
				if(first[counter]==second[counter])
					{if(counter==half-1)
						{
						add1(first,half);
						break;
						}
						counter++;
					}
				else
				if(first[counter]<second[counter])
				{
					if(mid!=9)
					{
						mid++;
						break;
					}
					else
					{mid=0;
					if(add1(first,half))
					half++;
					break;
					}
				}
			}
		for(int i=half-1;i>=0;i--)
		cout<<first[i];
		cout<<mid;
		for(int i=0;i<half;i++)
		cout<<first[i];
		}
		else 
		{
			half=l/2;
			for(int i=0;i<half;i++)
			{
				first[i]=s[half-i-1]-'0';
				second[i]=s[half+i]-'0';
			}
			while(true)
			{
				if(first[counter]>second[counter])
				break;
				else 
				if(first[counter]==second[counter])
				{	if(counter==half-1)
					{
					if(add1(first,half))
					half++;
					break;
					}
					counter++;
					found=true;
				}
				else
				if(first[counter]<second[counter])
				{
					if(found)
					{
					if(add1(first,half))
					half++;
					break;
					}
					bool temp=add1(first,half);
					if(first[counter]<second[counter])
					continue;
					break;
				}
			}
		for(int i=half-1;i>=0;i--)
		cout<<first[i];
		
		for(int i=0;i<half;i++)
		cout<<first[i];
	}
	cout<<endl;
	}
}
