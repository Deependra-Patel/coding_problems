#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;
char diffab(char a, char b){
	for(int i=0; i<26; i++){
		if(i!=a-'a' && i!=b-'a')
			return 'a'+i;
	}
}

int main(){
	int n, t;
	cin>>n>>t;
	string str1, str2;
	cin>>str1>>str2;
	vector<char> s1, s2;
	vector<int> diff, same;
	for(int i=0; i<n; i++){
		if(str1[i] == str2[i]){
			same.push_back(i);
		}
		else diff.push_back(i);
	}
	int x = diff.size();
	if(t<(x/2+x%2)){
		cout<<-1<<endl;
	}
	else {
		char* ans = new char[n];
		if(t<=x){
			int temp = x - t;
			for(int i=0;  i<temp; i++)
				ans[diff[i]] = str1[diff[i]];
			for(int i=temp;  i<2*temp; i++)
				ans[diff[i]] = str2[diff[i]];
			//cout<<ans[0];
			for(int i=2*temp; i<x; i++)
				ans[diff[i]] = diffab(str1[diff[i]], str2[diff[i]]);
			for(int i=0; i<same.size(); i++)
				ans[same[i]] = str1[same[i]];
		}
		else {
			for(int i=0; i<diff.size(); i++)
				ans[diff[i]] = diffab(str1[diff[i]], str2[diff[i]]);
			for(int i=0; i<t-diff.size(); i++)
				ans[same[i]] = diffab(str1[same[i]], 'z');
			for(int i=t-diff.size(); i<same.size(); i++)
				ans[same[i]] =str1[same[i]];			
		}
		for(int i=0; i<n; i++)
			cout<<ans[i];
		cout<<endl;
	}
}
