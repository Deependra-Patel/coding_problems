#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void calc(int &a, int &b, int &d, int n)
{
	int a1, b1, d1;
	int m=100000;
	if(n==1)
	{
		a=b=1;
		d=0;
	}
	else 
	{
		calc(a1,b1,d1,n/2);
		a=a1*a1+b1*b1;
		b=a1*b1+b1*d1;
		d=b1*b1+d1*d1;
		if(n%2!=0)
		{
			int tempb=b;
			b=a;
			d=tempb;
			a=a+tempb;
		}
		if(a>=m)
		{
			a%=m;
			if(b>=m)
			{
				b%=m;
				if(d>=m)
				d%=m;
			}
		}
	}
}
int main(){
	int ntest;
	cin>>ntest;
	for(int z=0; z<ntest; z++){
		vector<int> vec;
		int a, b, temp1, temp2, temp4, fiba, fibnext;
		cin>>a>>b;
		calc(temp1, temp2, temp4, a);
		cout<<temp4;
		fiba=temp4;
		calc(temp1, temp2, temp4, a+1);
		fibnext=temp4;
		vec.push_back(fiba);
		vec.push_back(fibnext);
		cout<<vec[0];
		if(b<100)
		for(int i=2; i<=b; i++){
			vec.push_back((vec[i-2]+vec[i-1])%100000);
		}
		else {
			for(int i=2; i<100; i++){
				int temp=(vec[i-2]+vec[i-1])%100000;
				vec.push_back(temp);
			}
			sort(vec.begin(), vec.end());
			for(int i=100; i<=b; i++){
				int temp=(vec[i-2]+vec[i-1])%100000;
				if(temp<vec[99]){
					vec[99]=temp;
					sort(vec.begin(), vec.end());
				}
			}
		}
		for(int i=0; i<min(100, b+1); i++)
		cout<<vec[i]<<endl;
	}
}
			
		
		
		
		
		
		
		
		
		
