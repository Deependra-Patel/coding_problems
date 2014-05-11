#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	long n,x,level,compare,sum=0;
	bool done;
	while(true)
	{
		done=false;
		level=1;
		sum=0;
		compare=2;
		cin>>n;
		if(n==0)
		break;
		if(n==1)
		{cin>>x;
		cout<<x<<endl;
		}
		else{
		while(true)
		{
			if(n<=compare-1)
			break;
			compare=compare*2;
			level++;
		}
		long long val=(long long)pow(2,level-1),last,last1,limit;
		last=n-val+1;
		last1=val/2-(last/2);
		if(last%2==1)
		last1--;
		limit=n-(last+last1);
		for(int i=0;i<n;i++)
		{
			cin>>x;
			if(done)
			sum+=x;
			else
			if(i+1==limit)
			done=true;
		}
		cout<<sum<<endl;
	}	
	}
}
