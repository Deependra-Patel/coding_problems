#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

vector<vector<int> > adjList;
int* cat;
int* done;
int m;

int calc(int index, int maxCat){
	//cout<<index<<" "<<maxCat;
	if(done[index])
		return 0;
	done[index] = true;
	int next;
	//cout<<index<<endl;
	if(cat[index])
		next = maxCat-1;
	else next = m+1;
	if(next == 0)
		return 0;
	if(adjList[index].size() == 1 && index!=0)
		return 1;
	int ans = 0;
	for(int i=0; i<adjList[index].size(); i++){
		ans += calc(adjList[index][i], next);
	}
	
	return ans;
}

int main(){
	int n;
	cin>>n>>m;
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
	//cout<<"d"<<endl;
	/*	if(n==2){
		if(cat[0] && cat[1]){
			if(m>1)
				cout<<1<<endl;
			else cout<<0<<endl;
		}
		else cout<<1<<endl;
	}
	else*/ cout<<calc(0, m+1)<<endl;
}
