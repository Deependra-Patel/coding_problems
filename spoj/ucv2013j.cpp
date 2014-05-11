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
		cout<<level;
		long long val=pow(2,level-1),limit;
		if(n+1<5*val/4)
		limit=val-1-val/4;
		else
		limit=val-1;
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
