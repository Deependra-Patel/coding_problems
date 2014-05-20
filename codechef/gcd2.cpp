#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int gcd(int a, int b)
{
	if (b==0)
		return a;
	else
		return gcd(b,a%b);
}
int main(){
	int ntest;
	cin>>ntest;
	while(ntest--){
		int a;
		string b;
		cin>>a;
		cin>>b;
		int pointer=0;
		int n=b.length();
		string cur="";
		cur[0]=b[0];
		if(atoi(cur.c_str())==0){
			cout<<a<<endl;
		}
		else if(a==0){
			cout<<b<<endl;
		}
		else {
			while(pointer!=n-1){
				int div_b=(atoi(cur.c_str()))%a;
				char  temp[50];
				sprintf(temp,"%d",div_b);
				string str(temp);
				cur=str+b[pointer+1];
				// cout<<div_b<<endl;
				// cout<<pointer<<" "<<cur<<endl;
				pointer++;
			}
			int b2=(atoi(cur.c_str()))%a;
			//cout<<b2;
			cout<<gcd(a, b2)<<endl;
		}
	}
}