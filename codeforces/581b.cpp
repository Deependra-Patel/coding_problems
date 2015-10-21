#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int* a = new int[n];
	for(int i=0; i<n ;i++) cin>>a[i];
	int b[n];
	int curMax = a[n-1];
	b[n-1] = 0;
	for(int i=n-2; i>=0; i--){
		b[i] = max(curMax - a[i] + 1, 0);
		curMax = max(curMax, a[i]);
	}
	for(int i=0; i<n; i++) cout<<b[i]<<" ";
	cout<<endl;
}
