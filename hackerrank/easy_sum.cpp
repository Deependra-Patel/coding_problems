#include <iostream>
using namespace std;
int main(){
	int ntest;
		//cout<<5*7/2;
	cin>>ntest;
	while(ntest--){
		long long int ans = 0;
		long long n;
		long long m;
		cin>>n>>m;
		long long int times = n/m;
		long long int remain = n%m;
		ans+=times*((m-1)*(m))/2 + remain*(remain+1)/2;
		cout<<ans<<endl;
	}
}