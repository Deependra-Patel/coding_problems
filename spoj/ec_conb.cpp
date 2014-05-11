#include <iostream>
#include <cstdio>
#include <math.h>
#include <string>
using namespace std;
int main(){
	int ntest;
	scanf("%d",&ntest);
	for(int z=0; z<ntest; z++){
		int n, revn=0;
		scanf("%d",&n);
		if(n%2!=0)
		printf("%d \n", n);
		else{
			n/=2;
			while(n!=0){
				revn=revn*2+n%2;
				n/=2;
			}	
		printf("%d \n", revn);
		}
	}
}
