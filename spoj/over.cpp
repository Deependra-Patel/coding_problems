#include <iostream>
using namespace std;
long long calc(int n, long long * arr){
	if(arr[n]!=-1)
	return arr[n];
	else {
		arr[n]=2*calc(n-1, arr)+ calc(n-2, arr);
		return arr[n];
	}
}
int main(){
	int ntest;
	cin>>ntest;
	long long ans[50];
	for(int i=0; i<50; i++)
	ans[i]=-1;
	ans[0]=3;
	ans[1]=7;
	for(int z=0; z<ntest; z++){
		int n;
		cin>>n;
		cout<<calc(n-1, ans)<<endl;
	}
}
