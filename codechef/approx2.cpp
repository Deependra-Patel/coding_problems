#include <iostream>
#include <math.h>
using namespace std;
int abs(int a){
	if(a>=0)
		return a;
	else return -a;
}
int main(){
	int ntest;
	cin>>ntest;
	while(ntest--){
		long long n, k;
		cin>>n>>k;
		int * arr=new int[n];
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}
		int count=0;
		long long diff=pow(10,10);
		for(int i=0; i<n; i++){
			for(int j=i+1; j<n; j++){
				if(abs(arr[i]+arr[j]-k) <diff){
					count=1;
					diff=abs(arr[i]+arr[j]-k);
				}
				else if(abs(arr[i]+arr[j]-k)==diff){
					count++;
				}
			}
		}
		cout<<diff<<" "<<count<<endl;
	}
}