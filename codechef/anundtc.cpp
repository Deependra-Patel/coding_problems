#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;
int main(){
	int ntest;
	cin>>ntest;
	while(ntest--){
		vector<int> vec;
		int n;
		cin>>n;
		char ans[3];
		if(360.0/n-360/n>0){
			ans[1]='n';
		}
		else ans[1]='y';
		if(n<=26)
			ans[2]='y';
		else ans[2]='n';
		if(n>360)
			ans[0]='n';
		else ans[0]='y';
		cout<<ans[1]<<" "<<ans[0]<<" "<<ans[2]<<endl;
	}
}
