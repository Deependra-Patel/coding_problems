#include <iostream>
using namespace std;

int main(){
	int na, nb;
	cin>>na>>nb;
	int k, m;
	cin>>k>>m;
	int x1, x2;
	for(int i=0; i<na; i++){
		int temp;
		cin>>temp;
		if(i == k-1)
			x1 = temp;
	}
	for (int j=0; j<nb; j++){
		int temp;
		cin>>temp;
		if(j==nb-m)
			x2 = temp;
	}
	if(x1<x2)
		cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
