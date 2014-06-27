#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>
#include <vector> 
#include <stdlib.h> 
using namespace std;
int main(){
	int n, m;
	cin>>n>>m;
	int * wt=new int[n];
	for(int i=0; i<n; i++)
		cin>>wt[i];
	vector<vector<int> > adj_max;
	for(int i=0; i<n; i++){
		vector<int> temp;
		for(int j=0; j<n; j++){
			temp.push_back(0);
		}
		adj_max.push_back(temp);
	}
	for(int t=0; t<m; t++){
		int i, j;
		cin>>i>>j;
		adj_max[i-1][j-1]=1;
		adj_max[j-1][i-1]=1;
	}
	// for(int i=0; i<n; i++){
	// 	for(int j=0; j<n; j++){
	// 		cout<<adj_max[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	int ans=0;
	for(int i=0; i<n; i++){
		int maxi=-1;
		int val=-1;
		for(int j=0; j<n; j++){
			if(wt[j]>maxi){
				maxi=wt[j];
				val=j;
			}
		}
		if(val==-1)
			break;
		//cout<<maxi<<endl;
		for(int j=0; j<n; j++){
			if(adj_max[val][j]!=0){
				//cout<<val<<j;
				ans+=wt[j];
				wt[val]=-1;
				adj_max[val][j]=0;
				adj_max[j][val]=0;
			}
		}
	}
	cout<<ans<<endl;
}