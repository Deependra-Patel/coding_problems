#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <set>
#include <map>
using namespace std;
int gcd(int a, int b){
	if(a%b == 0)
		return b;
	else return gcd(b, a%b);
}

int main(){
	int n;
	cin>>n;
	int m = n*n;
	int* inp = new int[n*n];
	for(int i=0; i<m; i++)
		cin>>inp[i];
	sort(inp, inp+m);
	map<int, int> gcds;
	map<int, int> nosCount;
	vector<int> nos;
	nos.push_back(inp[m-1]);
	if(n!=1){
		nos.push_back(inp[m-2]);
		gcds[gcd(inp[m-1], inp[m-2])] = 2;
		//		gcdsDone.push_back(0);
	}
	for(int j=m-3; j>=0; j--){		
		int x = inp[j];
		//cout<<j<<" "<<x<<endl;
		if(gcds[x] == 0){
			int size = nos.size();
			for(int i=0; i<size; i++){
				gcds[gcd(x, nos[i])] += 2;
			}
			nos.push_back(x);
		}
		else if(gcds[x] > nosCount[x]){
			nosCount[x] ++;
		}
		else {
			int size = nos.size();
			for(int i=0; i<size; i++){
				gcds[gcd(x, nos[i])] += 2;
			}
			nos.push_back(x);			
		}
	}
	for(int i=0; i<n; i++){
		cout<<nos[i]<<" ";
	}
	cout<<endl;
}
