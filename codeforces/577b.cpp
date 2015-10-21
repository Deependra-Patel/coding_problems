#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(){
	int n, m;
	cin>>n>>m;
	vector<int> reduced;
	for(int i=0; i<n; i++){
		int x;
		cin>>x;
		reduced.push_back(x%m);
	}
	sort(reduced.begin(), reduced.end());
	if(reduced[0] != 0){
		int i, j;
		i = 0;
		j = 1;
		while(i<n && j<n){
			
		}
	}
	else cout<<"YES"<<endl;
}
