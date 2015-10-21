#include <iostream>
#include <algorithm>
#include <map>
#include <stdio.h>
using namespace std;
struct edge{
	int a, b;
	int tax;
};
bool cmp(edge e1, edge e2){
	return e1.tax<e2.tax;
}

int find(int* parent, int x){
	if(parent[x] == -1)
		return x;
	else return find(parent, parent[x]);
}

void Union(int* parent, int x, int y){
	int px = find(parent, x);
	int py = find(parent, y);
	parent[px] = py;
}


int main(){
	int ntest;
	cin>>ntest;
	while(ntest--){
		int n, h;
		cin>>n>>h;
		edge* edges = new edge[h];
		map<int, bool> done;
		int* parent = new int[n];
		for(int i=0; i<n; i++){
			done[i] = false;
			parent[i] = -1;
		}
		for(int i=0; i<h; i++){
			edge temp;
			scanf("%d%d%d", &temp.a, &temp.b, &temp.tax);
			edges[i] = temp;
		}
		sort(edges, edges+h, &cmp);
		long long ans = 0;
		int cnt = n;
		for(int i=0; i<h; i++){
			if(cnt == 0)
				break;
			edge e = edges[i];
			int a = e.a;
			int b = e.b;
			if(find(parent, a-1) == find(parent, b-1))
				continue;
			else {
				Union(parent, a-1, b-1);
				ans += e.tax;
			}
			/*	if(done[a-1] && done[b-1])
				continue;
			else {
				ans += e.tax;
				cnt -= (!done[a-1] + !done[b-1]);
				done[a-1] = true;
				done[b-1] = true;
				}*/
		}
		printf("%llu\n", ans);
	}
}
