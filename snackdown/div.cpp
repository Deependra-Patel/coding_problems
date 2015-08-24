#include <iostream>
using namespace std;
int main(){
	int ntest;
	cin>>ntest;
	while(ntest--){
		string n;
		int sum = 0;
		cin>>n;
		int dec = 0;
		for(int i=0;i<n.length(); i++){
			sum+=n[i]-'0';
		}
		int mod = sum%9;
		if(n.length() == 1){
			if(mod<=4)
				cout<<mod<<endl;
			else cout<<9-mod<<endl;
		}
		else {
			if(sum-1>=mod){
				if(mod<=4)
					cout<<mod<<endl;
				else cout<<9-mod<<endl;
			}
			else cout<<9-mod<<endl;
		}
	}
}
