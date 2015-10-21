#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
int main(){
	int ntest;
	cin>>ntest;
	while(ntest--){
		int p, q, r, s;
		scanf("%d%d", &p, &q);
		char** a = new char*[p];
		for(int i=0; i<p; i++){
			a[i] = new char[q];
			for(int j=0; j<q; j++){
				scanf(" %c", &a[i][j]);
			}
		}

		scanf("%d%d", &r, &s);
		char** b = new char*[r];
		for(int i=0; i<r; i++){
			b[i] = new char[s];
			for(int j=0; j<s; j++)
				scanf(" %c", &b[i][j]);
		}

		bool logger = false;
		for(int i=0; i<p-r+1; i++){
			for(int j=0; j<q-s+1; j++){
				int broke = false;
				for(int x = i; x<r+i; x++){
					for(int y = j; y<s+j; y++){
						if(b[x-i][y-j] != '*' && b[x-i][y-j] != a[x][y]){
							broke = true;
							break;
						}
					}
				}
				if(!broke){
					logger = true;
					break;
				}
			}
		}
		if(logger)
			printf("Yes\n");
		else printf("No\n");
	}
}
