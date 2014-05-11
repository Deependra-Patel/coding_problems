#include <iostream>
#include <math.h>
using namespace std;

int max1(int* arr,int i,int j,int nth_day)
{
	if(i==j)
	return arr[i]*nth_day;
	else 
	{
		int val1=nth_day*arr[i]+max1(arr,i+1,j,nth_day+1);
		int val2=nth_day*arr[j]+max1(arr,i,j-1,nth_day+1);
		if(val1>val2)
		return val1;
		return val2;
	}
}
int main()
{
	int N,x;
	cin>>N;
	int arr[2001];
	for(int i=0;i<N;i++)
	{cin>>x;
		arr[i]=x;
	}
	cout<<max1(arr,0,N-1,1);
}
