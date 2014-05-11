#include <iostream>
#include <cmath>
using namespace std;
long long calc(int n,int i)
{
	if(n/(i+1)<=i)
	return 0;
	return (n/(i+1)-i+calc(n,i+1));
}
int main()
{
	long long n;
		cin>>n;
		if(n==0)
		cout<<n<<endl;
		cout<<calc(n,0)<<endl;
}
