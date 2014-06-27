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
	int n;
	cin>>n;
	int ans=0;
	int finala=0;
	for(int i=0; i<n; i++){
		int x;
		cin>>x;
		if(x!=0)
			ans++;
		else {
			finala=max(finala, ans);
			ans=0;
		}
	}
	cout<<max(finala, ans)<<endl;
}