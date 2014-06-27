#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>
#include <vector> 
#include <stdlib.h> 
using namespace std;
long long arr[15];
void init(){
	arr[0]=1;
	for(int i=1; i<15; i++){
		arr[i]=arr[i-1]*10+1;
	}
}
int main(){
	long long n;
	cin>>n;
	init();
	long long ans=0;
	int level=14;
	for(int i=0; i<15; i++)
		cout<<arr[i]<<endl;
	while(level>=1 && n!=0){
		long long dividend=n/arr[level];
		ans+=dividend*(level+1);
		n%=arr[level];
		level--;
		cout<<level<<" "<<n<<endl;
	}
	if(n!=0)
		ans+=n;
	cout<<ans<<endl;
}