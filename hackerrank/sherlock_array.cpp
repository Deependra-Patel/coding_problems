#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
int main(){
	int ntest;
	cin>>ntest;
	while(ntest--){
		int n;
		cin>>n;
		int * arr=new int[n];
		int sum=0;
		for(int i=0; i<n; i++){
			cin>>arr[i];
			sum+=arr[i];
		}
		int temp_sum=0;
		bool done=false;
		for(int i=0; i<n; i++){
			if(temp_sum==sum-temp_sum-arr[i]){
				done=true;
				//cout<<i;
				break;
			}
			temp_sum+=arr[i];
		}
		if(done)
			cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}