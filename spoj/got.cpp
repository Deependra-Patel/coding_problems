#include <iostream>
#include <string>
using namespace std;
int main(){
	string str;
	cin>>str;
	int count[26];
	for(int i=0; i<26; i++)
	count[i]=0;
	for(int i=0; i<str.length(); i++){
		count[str[i]-'a']++;
	}
	int con=0;
	for(int i=0; i<26; i++){
		if(count[i]%2!=0)
		con++;
	}
	if(con<2)
	cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
