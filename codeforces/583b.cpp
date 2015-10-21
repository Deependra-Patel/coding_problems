#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;
int main(){
	int n;
	cin>>n;
	int* arr = new int[n];
	int* done = new int[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
		done[i] = 0;
	}
	int cur = 0;
	int turns = 0;
	bool right = true;
	for(int i=0; i<n; i++){		
		int j;
		if(right)
			j = 0;
		else j = n-1;
		while(j>=0 && j<n){
			//	cout<<j<<" "<<cur<<endl;
			if(arr[j]<=cur && !done[j]){
				cur++;
				done[j] = 1;
			}				
			if(right)
				j++;
			else j--;
		}
		if(cur == n)
			break;
		right = !right;
		turns++;
	}
	cout<<turns<<endl;
}
