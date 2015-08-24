#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int* arr = new int[n];
	int a;
	cin>>a;
	for(int i=0; i<n; i++)
		arr[i] = 0;
	for(int i=0; i<a; i++){
		int x;
		cin>>x;
		arr[x-1] = 1;
	}
	int b;
	cin>>b;
	for(int i=0; i<b; i++){
		int x;
		cin>>x;
		arr[x-1] = 1;
	}
	int i;
	for(i=0; i<n;i++){
		if(arr[i]==0)
			break;
	}
	if(i == n)
		cout<<"I become the guy."<<endl;
	else cout<< "Oh, my keyboard!"<<endl;
}
