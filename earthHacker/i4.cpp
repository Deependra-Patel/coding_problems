#include <iostream>
#include <math.h>
using namespace std;
double maxi(double a, double b){
	if(a<b)
		return b;
	return a;
}
double pi = 3.141592653589793238;
int main(){
	double r, s;
	cin>>r>>s;
	double h = 0;
	double ans = 0;
	while(h<=s){
		double calc;
		double theta = sqrt(s*s-h*h);
		double alpha = (theta*h)/r;
		calc = (pi*((r+theta)*(r+theta)*h + (2*r+theta)*theta*alpha))/3;
		ans = maxi(ans, calc);
		h += 0.000001;
	}
	cout<<ans<<endl;
}
