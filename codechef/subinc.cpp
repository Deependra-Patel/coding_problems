#include <iostream>
using namespace std;
long long* arr;
struct my{
	long long minl, sum, numl, maxr, numr;
};

my solve(long long* arr, int n){
	if(n == 1){
		my ans;
		ans.minl = ans.maxr = arr[0];
		ans.sum = 1;
		ans.numl = ans.numr = 1;
		return ans;
	}
	my ans;
	ans.maxr = arr[n-1];
	ans.numr = 1;
	for(int i=n-2; i>=0; i--){
		if(arr[i]<= arr[i+1])
			ans.numr++;
		else break;
	}
	ans.minl = arr[0];
	ans.numl = 1;
	for(int i=1; i<n; i++){
		if(arr[i]>= arr[i-1])
			ans.numl++;
		else break;
	}
	
	my left = solve(arr, n/2);
	my right = solve(arr+n/2+n%2, n/2);
	if(n%2 == 0){
		ans.sum = left.sum + right.sum;
		if(left.maxr <= right.minl)
			ans.sum += left.numr*right.numl;
	}
	else {
		ans.sum = left.sum + right.sum;
		if(left.maxr <= arr[n/2] && arr[n/2] <= right.minl)
			ans.sum += (left.numr+1)*(right.numl+1);
		else if(left.maxr <= arr[n/2]){
			ans.sum++;
			ans.sum += left.numr;
		}
		else if(arr[n/2] <= right.minl){
			ans.sum++;
			ans.sum += right.numl;
		}
		else ans.sum++;
	}
	//	cout<<n<<" "<<ans.sum<<endl;
	return ans;
}
int main(){
	int ntest;
	cin>>ntest;
	while(ntest--){
		int n;
		cin>>n;
		arr = new long long[n];
		for(int i=0; i<n; i++)
			cin>>arr[i];
		cout<<solve(arr, n).sum<<endl;
	}
}
