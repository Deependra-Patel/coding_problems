#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>
#include <stdlib.h> 
using namespace std;
int main(){
	int ntest;
	cin>>ntest;
	while(ntest--){
		int n;
		cin>>n;
		int * arr=new int[n];
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}
		int sum1=0;
		int sum2=0;
		int last=1;
		for(int i=1; i<n; i++){
			if(abs(arr[i]-last)>abs(last-1)){
				sum1+=abs(arr[i]-last);
				last=arr[i];
			}
			else {
				sum1+=last-1;
				last=1;				
			}
		}
		last=arr[0];
		for(int i=1; i<n; i++){
			if(abs(arr[i]-last)>abs(last-1){
				sum2+=abs(arr[i]-last);
				last=arr[i];
			}
			else {
				sum2+=last-1;
				last=1;				
			}
		}
		cout<<max(sum2, sum1)<<endl;
	}
}