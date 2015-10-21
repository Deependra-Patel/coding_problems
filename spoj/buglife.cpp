#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
bool** adjMat;
int n;
int* color;
bool gay;
void dfsHelper(int cur, int curColor, vector<vector<int> > &adjList){
	//	cout<<adjList.size();
	int s = adjList[cur].size();
	for(int i=0; i<s; i++){
		if(color[adjList[cur][i]] == -1){
			color[adjList[cur][i]] = 1-curColor;				
			dfsHelper(adjList[cur][i], 1-curColor, adjList);
		}
		else if(color[adjList[cur][i]] == curColor){
			gay = true;
			return;
		}
	}
}

bool dfs(vector<vector<int> > &adjList){
	gay = false;
	for(int i=0; i<n; i++){
		if(color[i] == -1 && !gay){
			color[i] = 0;
			dfsHelper(i, 0, adjList);
		}
	}
	return gay;
}
/*
bool bfs(){
	for(int i=0; i<n; i++){
		if(level[i] != -1)
			continue;
		level[i] = 0;
		vector<int> nodes;
		nodes.push_back(i);
		int curLevel = 0;
		int size = nodes.size();
		for(int i=0; i<size;){
			int curNode = nodes[i];

			for(int j=0; j<n; j++){
				if(adjMat[curNode][j]){
					if(level[j]!=-1) {
						//		cout<<curNode<<" "<<j<<" "<<level[j]<<endl;
						if((level[j]-curLevel)%2==0)
							return false;
						else continue;
					}
					level[j] = curLevel+1;
					nodes.push_back(j);
				}
			}
			curLevel++;
			i = size;
			size = nodes.size();
		}
	}
	return true;
}
*/
int main()
{
	//	cout<<!1;
	int no_of_scenario;//,n_interactions,n_bugs,bugx,bugy,i;
	cin>>no_of_scenario;
	for(int z=0;z<no_of_scenario;z++)
	{
		int in;
		//cin>>n>>in;
		scanf("%d%d", &n, &in);
		adjMat = new bool*[n];
		color = new int[n];
		for(int i=0; i<n; i++)
			color[i] = -1;
		/*	for(int i=0; i<n; i++){
			adjMat[i] = new bool[n];
			for(int j=0; j<n; j++)
				adjMat[i][j] = false;
		}
		for(int i=0; i<in; i++){
			int x, y;
			cin>>x>>y;
			adjMat[x-1][y-1] = adjMat[y-1][x-1] = true;
			}*/

		vector<vector<int> > adjList(n);
		for(int i=0; i<in; i++){
			int x, y;
			//cin>>x>>y;
			scanf("%d%d", &x, &y);
			adjList[x-1].push_back(y-1);
			adjList[y-1].push_back(x-1);						
		}

		/*	for(int i=0; i<n; i++){
			for(int j=0; j<adjList[i].size(); j++)
				cout<<adjList[i][j]<<" ";
			cout<<endl;
			}*/
		bool odd = dfs(adjList);
		//	for(int i=0; i<n; i++)
		//	cout<<level[i]<<endl;
		if(!odd)
			printf("Scenario #%d:\nNo suspicious bugs found!\n",(z+1));
		else
			printf("Scenario #%d:\nSuspicious bugs found!\n", z+1);
	}
}
