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
	long long divi=pow(10,9)+7;
	long long count=0;
	for(int i=0; i<s.length(); i++){
		long long temp;
		temp=(ans*10+(count+1)*(s[i]-'0'))%divi;
		ans=(ans+temp)%divi;
		count=(count*2+1)%divi;
	}
	cout<<ans<<endl;
}