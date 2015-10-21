#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	int a, b;
	cin>>a>>b;
	if(b>a)
		cout<<-1<<endl;
	else {
		int c = a+b;
		int k = c/(2*b);
		double x1 = double(a+b)/(2*k);
		k = (a-b)/(2*b);
		double x2 = 1000000000000;
		if(k!=0)
			x2 = double(a-b)/(2*k);
	   
		if(x1<x2)
			cout<<setprecision(9)<<x1<<endl;
		else cout<<x2<<endl;
		//		cout<<min(x1, x2)<<endl;
	}
}
