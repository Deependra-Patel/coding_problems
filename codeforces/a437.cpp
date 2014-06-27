#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>
#include <stdlib.h> 
using namespace std;
bool calc(int x, int a,int b, int c){
	return ((2*x<=a && 2*x<=b && 2*x<=c) || (x>=2*a && x>=2*b && x>=2*c));
}
int main(){
	string a, b, c, d;
	cin>>a>>b>>c>>d;
	int a1, b1, c1, d1;
	a1=a.substr(2).length();
	b1=b.substr(2).length();
	c1=c.substr(2).length();
	d1=d.substr(2).length();
	int ct=0;
	char ans='0';
	if(calc(a1, b1, c1, d1)){
		ct++;
		ans='A';
	}
	if(calc(b1, a1, c1, d1)){
		ct++;
		ans='B';
	}
	if(calc(c1, b1, a1, d1)){
		ct++;
		ans='C';
	}
	if(calc(d1, b1, c1, a1)){
		ct++;
		ans='D';
	}
	if(ct==1)
		cout<<ans<<endl;
	else cout<<'C'<<endl;
}