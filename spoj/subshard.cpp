#include <iostream>
#include <string>
using namespace std;
int main(){
	int ntest;
	cin>>ntest;
	while(ntest--){
		string n;
		int m;
		cin>>n;
		cin>>m;
		long long ans = 0;
		long long terms = 0;
		for(int i=0; i<n.length(); i++){
			int dig = n[i]-'0';
			ans += ans*10 + (terms+1)*dig;
			ans = ans%m;
			terms = (2*terms+1)%m;
		}
	cout<<ans<<endl;
	}
}
