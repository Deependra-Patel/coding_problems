#include <iostream>
using namespace std;
int main(){
	int ntest;
	cin>>ntest;
	for(int z=0; z<ntest; z++){
		long long m,n;
		cin>>m>>n;
		if(m>n){
			if(n%2==0)
			cout<<"U";
			else cout<<"D";
		}
		else{
			if(m%2==0)
			cout<<"L";
			else cout<<"R";
		}
		cout<<endl;
	}
}
