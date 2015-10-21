#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;


int* cat;
int* done;
int m;
int ans;
struct mpair{
	int with, without;
};

mpair* calc(int index, vector<vector<int> > &adjList){

	done[index] = true;

	if(adjList[index].size() == 1 && index!=0){
		mpair* ans = new mpair();
		ans->with = !cat[index];
		ans->without = 0;
		return ans;
	}
	bool all = true;
	int withi, withouti;
	if(cat[index])
		withi=0;
	else withi = 1;
	withouti=0;
	for(int i=0; i<adjList[index].size(); i++){
		if(done[adjList[index][i]])
			continue;
		mpair* cur =  calc(adjList[index][i], adjList);
		withi += min(cur->without, cur->with);
		withouti += cur->with;
	}
	mpair* ans = new mpair();
	ans->with = withi;
	if(cat[index])
		ans->without = ans->with;
	else ans->without = withouti;
	return ans;
}

int main(){
	int ntest;
	cin>>ntest;
	while(ntest--){
		vector<vector<int> > adjList;
		int n;
		cin>>n;
		cat = new int[n];
		done = new int[n];
		for(int i=0; i<n; i++){
			done[i] = false;
			cin>>cat[i];
			vector<int> temp;
			adjList.push_back(temp);
		}
		//	cout<<"e"<<endl;
		for(int i=0; i<n-1; i++){
			int x, y;
			cin>>x>>y;
			x -= 1;
			y -= 1;
			adjList[x].push_back(y);
			adjList[y].push_back(x);
		}
		ans = 0;
		mpair* ans = calc(0, adjList);
		cout<<min(ans->with, ans->without)<<endl;
	}
}
