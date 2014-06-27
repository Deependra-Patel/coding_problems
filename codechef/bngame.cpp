#include <iostream>
#include <math.h>
using namespace std;

void calc(int arr[],int maxx[],int maxy[], int x[], int y[], int i, int n, int k){
	if(i+k>=n)
		return;

	if(arr[i]!=-1){
		return;
	}
	else {
		if(i+k<n)
			arr[i]=pow(10,9);

		for(int t=1; t<=k && i+t<n; t++){
			calc(arr, maxx, maxy, x, y, i+t, n, k);
			if(max(x[i],maxx[i+t])*max(y[i], maxy[i+t])<arr[i]){
				//cout<<i<<" ";
				arr[i]=max(x[i],maxx[i+t])*max(y[i], maxy[i+t]);
				maxx[i]=max(x[i],maxx[i+t]);
				maxy[i]=max(y[i], maxy[i+t]);
			}
		}
	}
}
int main(){

	long long n, k;
	cin>>n>>k;
	int * arr=new int[n];
	int * x=new int[n];
	int * y=new int[n];	
	int * maxx=new int[n];
	int * maxy=new int[n];
	for(int i=0; i<n; i++){
		cin>>x[i]>>y[i];
		if(i+k>=n){
			maxx[i]=x[i];
			maxy[i]=y[i];
			arr[i]=maxx[i]*maxy[i];
		}
		else {
			arr[i]=-1;
			maxx[i]=maxy[i]=-1;
		}
	} 
	int temp=pow(10,9);
	for(int i=0; i<k; i++){
		calc(arr, maxx, maxy, x, y, i, n, k);
		temp=min(temp, arr[i]);		
	}
/*	for(int i=0; i<n; i++){
		cout<<i<<endl<<"arr"<<arr[i]<<endl;
		cout<<"maxx"<<maxx[i]<<" "<<maxy[i]<<endl;
	}*/	
		cout<<temp<<endl;
}