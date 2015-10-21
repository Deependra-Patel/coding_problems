#include <iostream>
#include <vector>
#include <list>

using namespace std;
vector<vector<int> > adjList;
int n;
int bfs(int x){
	int* done = new int[n];
	for(int i=0 ;i<n ;i++) done[i] = false;
	list<int> li;
	for(int j=0; j<n; j++){
		if(done[j])
			continue;
		li.push_back(j);
		done[j] = true;
		while(!li.empty()){
			int x = li.front();
			cout<<x<<endl;
			li.pop_front();
			for(int i=0; i<adjList[x].size(); i++){
				if(!done[adjList[x][i]]){
					li.push_back(adjList[x][i]);
					done[adjList[x][i]] = true;
				}
			}
		}
	}
}

int dfsHelper(int* done, int node){
	done[node] = true;
	cout<<node<<endl;
	int len = adjList[node].size();
	for(int i=0; i<len; i++){
		if(!done[adjList[node][i]]){
			dfsHelper(done, adjList[node][i]);
		}
	}
	return 0;
}

int dfs(int x){
	int* done = new int[n];
	for(int i=0 ;i<n ;i++) done[i] = false;
	list<int> li;
	for(int j=0; j<n; j++){
		if(!done[j])
			dfsHelper(done, j);
	}
	return 0;
}

int main(){
	int m;
	cin>>n>>m;
	for(int i=0; i<n ;i++){
		vector<int> temp;
		adjList.push_back(temp);
	}
	
	for(int i=0; i<m; i++){
		int a, b;
		cin>>a>>b;
		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}
	//bfs(4);
	dfs(4);
}
