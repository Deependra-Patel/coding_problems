#include <iostream>
#include <vector>
using namespace std;
bool* traversed;
bool* set;
vector<int>* adjList;
bool cover(int ind){
	traversed[ind] = true;
	bool include = false;
	for(int i=0; i<adjList[ind].size(); i++){
		if(!traversed[adjList[ind][i]]){
			if(cover(adjList[ind][i]))
				include = true; 
		}
	}
	if(adjList[ind].size()==1){
		return true;
	}
	else if(include) {
		set[ind] = true;
		return false;
	}
	else return true;
}

int main(){
	int n;
	cin>>n;
	adjList = new vector<int>[n];
	traversed = new bool[n];
	set = new bool[n];
	for(int i=0; i<n; i++){
		traversed[i] = false;
		set[i] = false;
	}
	
	for(int i=0; i<n-1; i++){
		int x, y;
		cin>>x>>y;
		adjList[x-1].push_back(y-1);
		adjList[y-1].push_back(x-1);
	}
	if(cover(0)){
		for(int i=0; i<adjList[0].size(); i++){
			int ind = adjList[0][i];
			if(!set[ind]){
				set[0] = true;
				break;
			}
		}
	}

	int cnt = 0;
	for(int i=0; i<n; i++){
		if(set[i]) { cnt++;}
	}
	cout<<cnt<<endl;
}
