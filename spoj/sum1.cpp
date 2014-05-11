#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	long long num,sum3,sum5, sum15, num3,num5,num15;
	for(int z=0;z<n;z++)
	{
		sum3=0,sum5=0,sum15=0;
		cin>>num;
		num--;
		num3=num/3;
		num5=num/5;
		num15=num/15;
		sum3=(num3*(3+3*num3))/2;
		sum5=(num5*(5+5*num5))/2;
		sum15=(num15*(15+15*num15))/2;
		cout<<sum3+sum5-sum15<<endl;
	}
}

