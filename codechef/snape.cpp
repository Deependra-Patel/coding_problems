#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <stdlib.h>
using namespace std;
int main(){
	int ntest;
	cin>>ntest;
	int initial=ntest;
	while(ntest--){
		int b, ls;
		cin>>b>>ls;
		cout<<sqrt(ls*ls-b*b)<<" "<<sqrt(b*b+ls*ls)<<endl;
	}
}