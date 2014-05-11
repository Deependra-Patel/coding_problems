#include <iostream>
using namespace std;
int main(){
	int ntest;
	cin>>ntest;
	for(int z=0; z<ntest; z++){
		int n, t, d, sum=0;
		cin>>n>>t>>d;
		for(int i=0; i<n ;i++){
			int temp;
			cin>>temp;
			temp--;
			sum+=temp/d;
		}
		if(sum>=t)
		cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
