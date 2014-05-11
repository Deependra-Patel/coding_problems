#include <iostream>
using namespace std;
long long ans(long long n, long long * arr)
{
	if(arr[n-1]!=-1)
	return arr[n-1];
	if(n==0)
	return 0;
	else if(n==1)
	return 3;
	else if(n==2)
	return 7;
	else 
	{
		arr[n-1]=2*ans(n-1, arr)+ans(n-2, arr);
		return arr[n-1];
	}

}
int main()
{
	long long n;
	long long arr[100];
	for(int i=0;i<100;i++)
	arr[i]=-1;
	cin>>n;
	cout<<ans(n, arr)<<endl;
}
