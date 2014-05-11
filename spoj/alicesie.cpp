#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	long long limit;
	for(int z=0;z<n;z++)
	{
		cin>>limit;
		cout<<limit-limit/2<<endl;
	}
}
