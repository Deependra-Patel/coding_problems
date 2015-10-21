#include <iostream>
#include <map>
#include <stdio.h>
using namespace std;
int main(){
	int ntest;
	cin>>ntest;
	while(ntest--){
		int n, q;
		cin>>n>>q;
		map<int, int> mymap;
		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			mymap[x] = i;
		}
		for(int i=0; i<q; i++){
			int a, b;
			cin>>a>>b;
			bool no = true;
			a = mymap[a];
			b = mymap[b];
			int cnt = 0;
			if(b>=a){
				while(b>a){
					b = (b-1)/2;
					cnt++;
				}
				if(b == a)
					no = false;
			}

			if(no){
				printf("not an ancestor\n");
			}
			else {
				printf("%d-ancestor\n", cnt);
			}
		}
	}
}
