#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int m, n, k;
	cin>>m;
	cin>>n;
	cin>>k;
	int lawn[2000][2000];
	for(int i=0;i<2000;i++)
	for(int j=0;j<2000;j++)
	lawn[i][j]=-1;
	
	int* strip=new int[2000];
	int x;
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			cin>>x;
			lawn[i][j]=x;
		}
	}
	int sum;
	for(int j=0; j<n; j++)
	{
		sum=0;
		for(int i=0;i<k;i++)
		sum+=lawn[i][j];
		strip[j]=sum;
	}
	
	sum=0;
	int maxsum=0;
	for(int i=k-1; i<m; i++)	
	{
		sum=0;
		for(int t=0;t<k;t++)
		sum+=strip[t];
	
		for(int j=k; j<n;j++)
		{
			sum=sum+strip[j]-strip[j-k];
			maxsum=max(maxsum, sum);
		}
		for(int j=0 ;j<n;j++)
		strip[j]=strip[j]-lawn[i-k+1][j]+lawn[i+1][j];
	}
	cout<<maxsum<<endl;
	
}

