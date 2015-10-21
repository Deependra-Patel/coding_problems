#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

int main(){
	int n;
	cin>>n;
	int ans = 1;
	int last;
	cin>>last;
	int cur = 1;
	for(int i=1; i<n; i++){
		int x;
		cin>>x;
		if(x>=last){
			cur++;
		}
		else {
			ans = max(ans, cur);
			cur = 1;
		}
		last = x;
	}
	ans = max(ans, cur);
	cout<<ans<<endl;
}
