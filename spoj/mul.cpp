#include <iostream>
#include <string>
using namespace std;
int main()
{
	int no;
	cin>>no;
	string x1, x2;
	for(int z=0;z<no;z++)
	{
		cin>>x1;
		cin>>x2;
		int l1=x1.length();
		int l2=x2.length();
		long long a[1250], b[1250], ans[2500];
		bool flag1=false, flag2=false;
		
		int i=l1-1,j=0;
		long long c=0, factor=1;
		while(i>=0)
		{
			c+=(x1[i]-'0')*factor;
			if(factor==100000000)
			{
				a[j]=c;
				if(a[j]!=0)
				flag1=true;
				c=0;
				j++;
				factor=1;
			}
			else 
			factor*=10;
			i--;
		}
		if(c!=0)
		{
			a[j]=c;
			flag1=true;
		}
		factor=1;
		c=0;i=l2-1;
		while(i>=0)
		{
			c+=(x2[i]-'0')*factor;
			if(factor==100000000)
			{
				b[j]=c;
				if(b[j]!=0)
				flag2=true;
				c=0;
				j++;
				factor=1;
			}
			else 
				factor*=10;
				i--;
		}
		if(c!=0)
		{
			b[j]=c;
			flag2=true;
		}
		
		int l18=(l1-1)/8+1;
		int l28=(l2-1)/8+1;

	if(flag1 && flag2)
	{
		for(int i=0;i<2500;i++)
		{
			ans[i]=0;
		}
		for(int i=0;i<l28;i++)
		{
			for(int j=0;j<l18;j++)
			{
				ans[i+j]+=b[i]*a[j];
			}
		}
		int c=0;
		for(int i=0;i<l18+l28;i++)
		{
			ans[i]+=c;
			c=ans[i]/(100000000);
			ans[i]=ans[i]%(100000000);
		}
		bool flag=false;
		for(int i=2500-1;i>=0;i--)
		{
			if(flag)
			cout<<ans[i];
			else if(ans[i]!=0)
			{
				cout<<ans[i];
				flag=true;
			}
		}
	}
	else cout<<'0';
	cout<<endl;
	}
	
}







