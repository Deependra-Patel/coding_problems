#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int * arr = new int[n];
	for(int i=0; i<n; i++)
		cin>>arr[i];
	while(arr[0]%2==0){
		arr[0] /= 2;
	}
	while(arr[0]%3==0){
		arr[0] /= 3;
	}
	bool yes = true;
	for(int j=1; j<n; j++){
		while(arr[j]%2==0){
			arr[j] /= 2;
		}
		while(arr[j]%3==0){
			arr[j] /= 3;
		}
		if(arr[j] != arr[0]){
			yes = false;
			break;
		}
	}
	if(yes)
		cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
