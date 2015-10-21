#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;
double myabs(double a1){
	if(a1>0)
		return a1;
	else return -a1;
}
double mypow(double x, int n){
	unsigned double ans = x;
	for(int i=1; i<n; i++)
		ans *= x;
	return ans;
}
double newton(int n, double a){
	double xk, xk1;
	xk = 1;
	while(myabs(a-mypow(xk,n))>0.000001){
		xk = ((n-1)*xk + a/(mypow(xk, n-1)))/n;
		//cout<<a-mypow(xk,n)<<" ";
		cout<<xk<<endl;
	}
	return xk;
}

int main(){
	int ntest;
	cin>>ntest;
	for(int z = 1; z<=ntest; z++){
		printf("Case #%d:\n", z);
		int n, m;
		cin>>n>>m;
		int* arr = new int[n];
		for(int i=0; i<n; i++)
			cin>>arr[i];
		for(int i=1; i<=m; i++){
			int d1, d2;
			cin>>d1>>d2;
			double volume = 1.0;
			for(int k=d1; k<=d2; k++){
				volume *= arr[k];
			}
			int n2 = d2-d1+1;
			cout<<fixed<<setprecision(8)<<newton(n2, volume)<<endl;
		}
	}
}
