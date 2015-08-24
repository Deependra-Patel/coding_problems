#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int n, k;
	cin>>n>>k;
	int* arr = new int[n];
	for(int i=0; i<n; i++)
		cin>>arr[i];
	sort(arr, arr+n);
	int indS = 0;
	int* ans = new int[n];
	for(int i=0; i<k; i++){
		int indA = i;
		while(indA<n && indS<n){
			ans[indA] = arr[indS];
			indA += k;
			indS++;
		}
	}
	long long sum = 0;
	for(int i=0; i<n-k; i++)
		sum += ans[i+k] - ans[i];
	cout<<sum<<endl;
	for(int i=0; i<n; i++)   
		cout<<ans[i]<<" ";
}
