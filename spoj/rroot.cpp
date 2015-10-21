#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int main(){
	int ntest;
	cin>>ntest;
	while(ntest--){
		double x;
		cin>>x;
		double t = 1 - (2/(3*(sqrt(2*x))));
		cout<<setprecision(6)<<t<<endl;
	}
}
