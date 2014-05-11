#include <iostream>
using namespace std;
#include <vector>
#include <math.h>
int main()
{
	long long n,x,nth,index;
	int last;
	cin>>n;
	long long input[1000000];
	vector<int> store;
	for(int a=0;a<10;a++)
		for(int b=0;b<10;b++)
			for(int c=0;c<10;c++)
			{
				x=a*100+b*10+c;
				if((x*x*x)%1000==888)
				store.push_back(x);
			}
	for(int i=0;i<n;i++)
	{
	cin>>input[i];
	}
	for(int x=0;x<n;x++)
	{
	nth=input[x];
	nth=nth-1;
	index=nth/4;
	last=nth%4;	
	if(index==0)
	cout<<store[last];
	else
	cout<<index<<store[last];
	cout<<endl;
	}
}
