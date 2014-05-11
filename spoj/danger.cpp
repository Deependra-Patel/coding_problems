#include <iostream>
#include <cstdio>
#include <math.h>
#include <string>
using namespace std;
int survivor(int n){
	if(n==1)
	return 1;
	else if(n==2)
	return 1;
	else if(n%2==0)
	return 2*(survivor(n/2))-1;
	else {
		int last=survivor((n+1)/2);
		if(last==1)
		return n;
		else return 2*(last-1)-1;
	}
}
int main(){
	char temp[4];
	string s;
	scanf("%s",temp);
	s=temp;
	while(s!="00e0"){
		int pre=(s[1]-'0')+10*(s[0]-'0');
		int pwr=(s[3]-'0');	
		printf("%d\n",survivor(pre*pow(10,pwr)));
		scanf("%s", temp);
		s=temp;
	}
}
