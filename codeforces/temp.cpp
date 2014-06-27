#include <iostream>
#include <vector>
using namespace std;
int ch[4];
int s(int p){
	for(int i=0; i<4; i++)
		if(i!=p){
			if(ch[p]*2>ch[i])
				return false;
		}
	return true;
}
int b(int p){
	for(int i=0; i<4; i++)
		if(i!=p){
			if(ch[p]<2*ch[i])
				return false;
		}
	return true;
}
int main(){
	for(int i=0; i<4; i++){
		string a;
		cin>>a;
		ch[i]=a.size()-2;
	}
	vector<int> ans;
	for(int i=0; i<4; i++){
		if(s(i))
			ans.push_back(i);
		if(b(i))
			ans.push_back(i);
	}
	if(ans.size()==1)
		cout<<char('A'+ans[0]);
	else cout<<'C';
}