#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main()
{
	long long n,num,temp,size,ahead;
	cin>>n;
	for(long long i=0;i<n;i++)
	{
		cin>>num;
		temp=2;
		size=1;
		while(num>temp)
		{
			temp=2*(temp+2)-2;
			size++;
		}
		temp=(long long)(num-pow(2,size)+2);
		temp--;
		vector<long long> v;
		long counter=1;
		while(temp>=1 && counter<=size)
		{
			if(temp%2==0)
			v.push_back(5);
			else
			v.push_back(6);
			temp=temp/2;
			counter++;
		}
		for(long long i=0;i<size-v.size();i++)
		cout<<'5';
		for(int i=v.size()-1;i>=0;i--)
		cout<<v[i];
		cout<<endl;
	}
}
