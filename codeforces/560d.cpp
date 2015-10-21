#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;
char* a, *b;
int n;

bool check(char* c1, char* c2, int size){
	if(size == 1){
		return c1[0] == c2[0];
	}
	int i;
	for(i=0; i<size; i++) if(c1[i]!=c2[i])break;
	if(i == size)
		return true;
	if(size%2 == 0)
		return (check(c1, c2, size/2) && check(c1+size/2, c2+size/2, size/2))||(check(c1+size/2, c2, size/2) &&  check(c1, c2+size/2, size/2));
	else return false;//(check(c1, c2, size/2) && check(c1+size/2+1, c2+size/2+1, size/2)) || (check(c1+size/2+1, c2, size/2) &&  check(c1, c2+size/2+1, size/2));
	//cout<<size<<" "<<x<<endl;	
	//return x;
}

int main(){
	string s1, s2;
	cin>>s1>>s2;
	n = s1.length();
	a = new char[n];
	b = new char[n];
	for(int i=0; i<n ;i++){
		a[i] = s1[i];
		b[i] = s2[i];
	}
	if(check(a, b, n)){
		cout<<"YES"<<endl;
	}
	else cout<<"NO"<<endl;
}
