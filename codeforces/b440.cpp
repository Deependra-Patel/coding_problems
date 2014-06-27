#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>
#include <vector> 
#include <stdlib.h> 
using namespace std;
int next_ex_ind(int arr[], int extra_index, int n, int k){
	int ex=extra_index;
	for(int i=extra_index+1; i<n; i++){
		if(arr[i]>k){
			ex=i;
			break;
		}	
	}	
	return ex;
}
int main(){
	long long n;
	cin>>n;
	int * arr=new int[n];
	int sum=0;
	for(int i=0; i<n; i++){
		cin>>arr[i];
		sum+=arr[i];
	}
	int k=sum/n;
	int ans=0;
	int extra_index=next_ex_ind(arr, -1, n, k);
	for(int i=0; i<n; i++){
		if(arr[i]<k){
			int extra=arr[extra_index]-k;
			if(extra>k-arr[i]){
				arr[extra_index]=k+extra-(k-arr[i]);
				ans+=(k-arr[i])*abs(extra_index-i);
			}
			else if(extra==k-arr[i]){
				ans+=(k-arr[i])*abs(extra_index-i);
				extra_index=next_ex_ind(arr, extra_index, n, k);
			}
			else {
				while(arr[i]<k){
					arr[i]+=arr[extra_index]-k;
					ans+=(arr[extra_index]-k)*abs(extra_index-i);
					arr[extra_index]=k;
					extra_index=next_ex_ind(arr, extra_index, n, k);
				}
				int diff=arr[i]-k;
				ans-=(diff)*abs(extra_index-i);
				arr[extra_index]+=diff;
				if(arr[extra_index]==k){
					extra_index=next_ex_ind(arr, extra_index, n, k);					
				}
			}
		}
	}
	cout<<ans<<endl;

}