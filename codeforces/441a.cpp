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
	int n, p;
	cin>>n>>p;
	vector<int> dealers;
	for(int i=0; i<n; i++){
		int no;
		cin>>no;
		bool done=false;
		while(no--){
			int x;
			cin>>x;
			if(x<p){
				done=true;
				//cout<<x<<endl;
			}
		}
		if(done)
			dealers.push_back(i+1);
	}
	cout<<dealers.size()<<endl;
	for(int i=0; i<dealers.size(); i++)
		cout<<dealers[i]<<" ";
	cout<<endl;
}