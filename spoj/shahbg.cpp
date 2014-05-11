#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	long index[20001],n,x,grp=0;
	cin>>n;
	for(int i=0;i<20001;i++)
	index[i]=0;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		if(x==1 && index[x]==0)
			grp++;
		else if((x==n) && (index[x-2]==0))
			grp++;
		else if(index[x]==1 && index[x-2]==1)
			grp--;
		else if(index[x]==0 && index[x-2]==0)
		grp++;
		index[x-1]=1;
		cout<<grp<<endl;
	}
	cout<<"Justice"<<endl;		
	return 0;
}
