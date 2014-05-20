#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;
int main(){
	int ntest;
	cin>>ntest;
	while(ntest--){
		vector<int> vec;
		int n;
		cin>>n;
		int x;
		cin>>x;
		vec.push_back(x);
		for(int i=1; i<n; i++){
			int x;
			cin>>x;
			if(i%2==0){
				if(vec[i-1]>=x)
					vec.push_back(x);
				else {
					vec.push_back(vec[i-1]);
					vec[i-1]=x;
				}
			}
			else {
				if(vec[i-1]<=x)
					vec.push_back(x);
				else {
					vec.push_back(vec[i-1]);
					vec[i-1]=x;
				}				
			}
		}
		for(int i=0;i<n; i++)
			cout<<vec[i]<<" ";
		cout<<endl;
	}
}
