#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
int s1;
int s2;
void calc(char* m1,char* m2){
	char ans[60];
	for(int i=0; i<60; i++)
		ans[i]='0';
	int carry=0;
	for(int i=0; i<s2; i++){
		int temp=m2[i]-'0';
		temp+=10*carry;
		carry = temp%2;
		m2[i]=temp/2;
	}
	 

}
int main(){
	int ntest;
	scanf("%d", &ntest);
	for(int i=0; i<ntest; i++){
		char m1[30], m2[30];
		scanf("%s %s", m1, m2);
		string s1(m1), s2(m2);
		int m=s1.length();
		int n=s2.length();
		s1=m;
		s2=n;
		if(m==n){
			if(s1>s2)
				calc(m1, m2);
			else calc(m2,m1);
		}
		else if(m>n)
			calc(m1, m2);
		else calc(m2, m1);
		/*int m=s1[s1.length()-1]-'0', n=s2[s2.length()-1]-'0';
		if(m%2==0){
			if(n%2==0)
			printf("%d \n",n*(m/2));
			else printf("%d \n", m*(n+1)/2);
		}
		else
		printf("%d \n",n*(m+1)/2);*/
	}
}
		
			
