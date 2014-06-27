#include <iostream>
using namespace std;
int gcd2(int a, int b){
	if(a%b==0){
		return b;
	}
	else gcd2(b, a%b);
}

int gcd(int a, int b){
	if(a>b){
		return gcd2(a, b);
	}
	else return gcd2(b, a);
}

int main(){
	int a, b;
	cin>>a>>b;
	cout<<gcd(a,b)<<endl;
}