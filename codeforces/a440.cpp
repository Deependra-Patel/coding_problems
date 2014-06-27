#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>
#include <vector> 
#include <stdlib.h> 
using namespace std;
int main(){
	long long n;
	cin>>n;
	long long sum=0;
	for(int i=0; i<n-1; i++){
		int x;
		cin>>x;
		sum+=x;
	}
	cout<<(n*n+n)/2-sum<<endl;
}