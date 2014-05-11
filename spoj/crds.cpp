#include <iostream>
using namespace std;
int main(){
	int ntest;
	cin>>ntest;
	for(int z=0; z<ntest; z++){
		long long n;
		cin>>n;
		cout<<(n*(3*n+1)/2)%1000007<<endl;
	}
}
