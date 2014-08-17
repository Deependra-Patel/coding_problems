#include <iostream>
using namespace std;
int main(){
	int ntest;
	cin>>ntest;
	while(ntest--){
		int w, b;
		cin>>w>>b;
		if(b%2==0)
			cout<<"0.000000"<<endl;
		else cout<<"1.000000"<<endl;
	}
}