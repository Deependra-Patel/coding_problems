#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>
#include <vector> 
#include <stdlib.h> 
using namespace std;
bool check_pal(string s, int i){
			bool check=true;
			for(int j=0,k=s.length()-1; j<s.length()-1; j++, k--){
				if(j==i)
					j++;
				if(k==i)
					k--;
				if(s[j]!=s[k]){
					check=false;
					break;
				}
			}
	return check;	
}
int main(){
	int ntest;
	cin>>ntest;
	while(ntest--){
		string s;
		cin>>s;
		int l=s.length();
		int ans=-1;
		for(int i=0; i<l/2; i++){
			if(s[i]!=s[l-1-i]){
				//cout<<"i"<<i;
				if(check_pal(s, i))
					ans=i;
				else ans=l-1-i;
				break;
			}
		}
		cout<<ans<<endl;
	}
}