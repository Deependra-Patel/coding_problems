#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
int main(){
	int ntest;
	scanf("%d", &ntest);
	for(int i=0; i<ntest; i++){
		char m1[30], n1[30];
		scanf("%s %s", m1, n1);
		string s1(m1), s2(n1);
		int m=s1[s1.length()-1]-'0', n=s2[s2.length()-1]-'0';
		if(m%2==0){
			if(n%2==0)
			printf("%d \n",n*(m/2));
			else printf("%d \n", m*(n+1)/2);
		}
		else
		printf("%d \n",n*(m+1)/2);
	}
}
		
			
