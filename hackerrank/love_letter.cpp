#include <iostream>
#include <string>
using namespace std;
int main(){
	int ntest;
	cin>>ntest;
	while(ntest--){
		string s;
		cin>>s;
		int l=s.length();
		int ans=0;
		if(l!=1){
			for(int i=0; i<l/2; i++){
				ans+=max(s[i], s[l-i-1])-min(s[i], s[l-i-1]);
			}
		}
		cout<<ans<<endl;
	}
}