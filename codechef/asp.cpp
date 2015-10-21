#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	int ntest;
	cin>>ntest;
	while(ntest--){
		int n;
		scanf("%d", &n);
		long long* arr = new long long[n];
		for(int i=0; i<n ;i++) scanf("%lli", &arr[i]);

		
		long long maxi;
		if(n>2)
			maxi = arr[0];
		int i;
		for(i=2; i<n; i++){
			if(arr[i]<maxi){
				break;
			}
			maxi = max(maxi, arr[i-1]);
		}
		if(n==1 || n==2 || i == n)
			printf("YES\n");
		else printf("NO\n");
	}
}
