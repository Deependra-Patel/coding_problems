#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
int main(){
	int ntest;
	string s;
	cin>>s;
	long long ans=0;
	long long last=0;
	long long divi=pow(10,9)+7;
	for(int i=0; i<s.length(); i++){
		long long temp;
		temp=(last*10+(i+1)*(s[i]-'0'))%divi;
		ans=(ans+temp)%divi;
		last=temp;
	}
	cout<<ans<<endl;
}