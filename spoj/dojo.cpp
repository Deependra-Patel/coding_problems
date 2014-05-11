#include <iostream>
#include <cstdio>
#include <math.h>
#include <string>
using namespace std;
int main(){
	int ntest;
	scanf("%d",&ntest);
	for(int z=0; z<ntest; z++){
		int n, i;
		char m1[2001], j1[2001]; 
		scanf("%d %s %d %s", &n, m1, &i, j1);
		string m(m1), j(j1); 
		if((m[m.length()-1]%2==0 || n%2==0)|| (i+j[j.length()-1])%2!=0)
		printf("Impossible. \n");
		else 
		printf("Possible. \n");
	}
}
