#include <iostream>
#include <math.h>
#include <string>
#include <stdlib.h>
using namespace std;
int gcd(int a, int b)
{
	if (b==0)
		return a;
	else
		return gcd(b,a%b);
}
int main(){
	int ntest;
	cin>>ntest;
	while(ntest--){
		string str;
		cin>>str;
		int pos = str.find('.');
		//cout<<pos<<endl;
		if(pos == -1)
			cout<<1<<endl;
		else {
			int denom = pow(10, str.length()-pos-1);
			int num = atoi(str.substr(pos+1).c_str());
			int gc = gcd(denom, num);
			cout<<denom/gc<<endl;
		}	
	}
}

