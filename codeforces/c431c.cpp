#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
int main(){
	int arr[4];
	cin>>arr[0]>>arr[1]>>arr[2]>>arr[3];
	string s;
	cin>>s;
	long long ans=0;
	for(int i=0; i<s.length(); i++)
		ans+=arr[s[i]-'1'];
	cout<<ans<<endl;
}