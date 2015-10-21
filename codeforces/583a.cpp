#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;
int main(){
	int n;
	cin>>n;
	int m = n*n;
	vector<int> ans;
	int* doneH = new int[n];
	int* doneV = new int[n];
	for(int i=0; i<n; i++) doneH[i] = doneV[i] = 0;
	for(int i=0; i<m;  i++){
		int h, v;
		cin>>h>>v;
		if(!doneH[h-1] && !doneV[v-1]){
			ans.push_back(i+1);
			doneH[h-1] = 1;
			doneV[v-1] = 1;
		}
	}
	for(int i=0; i<ans.size(); i++)
		cout<<ans[i]<<" ";
	cout<<endl;
}
