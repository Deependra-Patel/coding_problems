#include <iostream>
using namespace std;
int main(){
	int a[3];
	cin>>a[0]>>a[1]>>a[2];
	while(!(a[0]==0 && a[1]==0 && a[2]==0)){
		if(2*a[1]==a[0]+a[2])
		cout<<"AP "<<2*a[2]-a[1]<<endl;
		else 
			cout<<"GP "<<a[2]*a[2]/a[1]<<endl;
		cin>>a[0]>>a[1]>>a[2];
	}
}
