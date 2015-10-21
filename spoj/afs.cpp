#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
struct seq1
{
	vector<long long> tabl;
	int num;
	void init()
	{
		num = 1000001;
	tabl.assign(num,1);
	tabl[0]=0;
	tabl[1]=0;
	}
	void fill(){
		for(long long i=2; i<num; i++){
			long long temp = 2*i;
			while(temp<num){
				tabl[temp] += i;
				temp += i;
			}
		}

		for(long long i=1; i<num; i++){
			tabl[i] += tabl[i-1];
		}
	}
	long long calculate(int nth)
	{
		return tabl[nth];
	}
};
int main()
{
	int n,x;
	cin>>n;
	seq1 all;
	all.init();
	all.fill();
	for(int i=0;i<n;i++)
	{cin>>x;
	cout<<all.calculate(x)<<endl;
	}
}
	
