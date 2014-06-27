#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>
#include <stdlib.h> 
using namespace std;
int main(){
	int n;
	cin>>n;
	int last_finish=0;
	int last_num=-1;
	long long ans=0;
	int * arr=new int[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	for(int i=0; i<n ;i++){
		int x=arr[i];

			int temp_min=x;
			for(int j=i; j>=0; j--){
				if(arr[j]<temp_min){
					ans++;
					temp_min=arr[j];
				}
			}
			ans++;
	}
	cout<<ans<<endl;
}