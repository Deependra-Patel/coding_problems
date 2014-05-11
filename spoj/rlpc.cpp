#include <iostream>
using namespace std;
int main()
{
	long long n,no,min=0,x,sum;
	cin>>n;
	for(long long i=0;i<n;i++)
	{
		cin>>no;
		cin>>x;
		min=x;
		sum=x;
		if(sum<min)
		min=sum;
		for(long long j=0;j<no-1;j++)
		{
			cin>>x;
			sum+=x;
			if(sum<min)
			min=sum;
		}
		if(min>=0)
		cout<<"Scenario #"<<(i+1)<<": "<<1<<endl;
		else
		cout<<"Scenario #"<<(i+1)<<": "<<-min+1<<endl;
	}
	
}
