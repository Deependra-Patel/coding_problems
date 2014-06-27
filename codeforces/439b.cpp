#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>
#include <vector> 
#include <stdlib.h> 
#include <iomanip>
#include <algorithm>
using namespace std;
int main(){
	int n, x;
	cin>>n>>x;
	long long sum=0;
	int temp=n;
	vector<int> vec(n);
	for(int i=0; i<n; i++){
		cin>>vec[i];
	}
	sort(vec.begin(), vec.end());
	for(int i=0; i<n; i++){
		cout<<vec[i]<<endl;
	}
	for(int i=0; i<n; i++){
		if(x==1){
			sum+=vec[i];
		}
		else {
			sum+=x*vec[i];
			x--;
		}
	}
	cout<<sum<<endl;
}