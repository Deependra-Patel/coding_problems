#include <iostream>
using namespace std;
int main(){
	int t, s, q;
	cin>>t>>s>>q;
	int temp = s*q;
	int cnt = 1;
	while(temp<t){
		temp = temp*q;
		cnt++;
	}
	cout<<cnt<<endl;
}
