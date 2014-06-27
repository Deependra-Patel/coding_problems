#include <algorithm>   
#include <vector> 
#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>
#include <stdlib.h> 
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> vec;
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		vec.push_back(temp);
	}

	// sort(vec.begin(), vec.end());
	int p, q;
	cin>>p>>q;
	int maxi=-1;
	int ans=-1;
	if(vec[0]>=p){
		maxi=vec[0]-p;
		ans=p;
		p=vec[0];
	}
	if(q>vec[n-1]){
		if(maxi<q-vec[n-1]){
			maxi=q-vec[n-1];
			ans=q;
		}
		q=vec[n-1];
	}
	for(int i=p; i<=q; i++){
		int mini=999999999;
		int temp_val=-1;
		for(int j=0; j<n; j++){
			if(abs(vec[j]-i)<mini){
				temp_val=i;
				mini=abs(vec[j]-i);
			}
		}
		if(mini>maxi){
			maxi=mini;
			ans=temp_val;
		}
	}
	cout<<ans<<endl;
	// int maxi=-1;
	// int ans=-1;
	

	// for(int i=1; i<n ;i++){
	// 	int avg=(vec[i]+vec[i-1])/2;
	// 	if(max(vec[i]-avg, avg-vec[i-1])>maxi){
	// 		if()
	// 	}
	// }
}