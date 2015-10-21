#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace  std;
int main(){
	long long n;
	cin>>n;
	int * arr = new int[n];
	for(int i=0; i<n; i++)
		cin>>arr[i];
	sort(arr, arr+n);
	int ans = 1;
	int curval = arr[0];
	int cnt = 1;
	for(int i=1; i<n; i++){
		if(arr[i] == curval){
			curval ++;
			cnt = 1;
		}
		else if(arr[i] < curval){
			cnt++;
		}
		else {
			cnt = 0;
			ans ++;
			curval = arr[i];
		}
	}
	cout<<ans<<endl;
}
