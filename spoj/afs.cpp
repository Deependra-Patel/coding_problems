#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
struct seq1
{
	vector<int> tabl;
	void init()
	{
	tabl.assign(1000000,-1);
	tabl[0]=0;
	tabl[1]=0;
	}
	int sum_divisors(int n)
	{
		int sum=0;
		for(int i=1;i<=sqrt(n);i++)
		{
			if(n%i==0)
			sum+=i;
		}
		return sum;
	}
	int calculate(int nth)
	{
		if(tabl[nth]!=-1)
		return tabl[nth];
		else
		{
			tabl[nth]=calculate(nth-1)+sum_divisors(nth);
			return tabl[nth];
		}
	}
};
int main()
{
	int n,x;
	cin>>n;
	seq1 prime;
	prime.init();
	for(int i=0;i<n;i++)
	{cin>>x;
	cout<<prime.calculate(x)<<endl;
	}
}
	
