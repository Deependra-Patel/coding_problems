#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	double n;
	cin>>n;
	while(n!=0){
		printf("%.2f",(n*n)/(2.0*3.14159));
		cout<<endl;
		cin>>n;
	}
}
