#include <iostream>
using namespace std;
long long nCrmod(int n,int r, int c[200][200])
{
	if(c[n][r]!=-1)
	return c[n][r];
	else
	if((r==0 || (n==r)) && (n>=0))
	return 1;
	else
	if(r<0||n<1||n<r)
	return 0;
	else
	{
		if(c[n-1][r]!=-1)
		c[n][r]=(c[n-1][r]+nCrmod(n-1,r-1, c))%1000000007;
		
		else if(c[n-1][r-1]!=-1)
		c[n][r]=(c[n-1][r-1]+nCrmod(n-1,r , c))%1000000007;
		else
		c[n][r]=(nCrmod(n-1,r, c)+nCrmod(n-1,r-1, c))%1000000007;
		return c[n][r];
	}
}
int main()
{
	int no;
	cin>>no;
	int c[200][200];
	for(int i=0;i<200;i++)
	{
		for(int j=0;j<200;j++)
		c[i][j]=-1;
	}
	for(int z=0;z<no;z++)
	{
		int n,m;
		cin>>n>>m;
		cout<<nCrmod(n+m-2,n-1,c)<<endl;
	}
}
