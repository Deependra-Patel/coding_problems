#include <iostream>
using namespace std;
int gcd(int x, int y)
{
	if(y==0)
	return x;
	else 
	return gcd(y,x%y);
}
int main()
{
	int no;
	cin>>no;
	for(int i=0;i<no;i++)
	{
		int a, b, gc;
		cin>>a>>b;
		gc=gcd(a,b);
		cout<<(b/gc)<<" "<<(a/gc)<<endl;
	}
	
}
