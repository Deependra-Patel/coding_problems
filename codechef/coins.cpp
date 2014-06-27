#include <iostream>
#include <map>
#include <math.h>
#include <stdlib.h>
using namespace std;
map<long long, long long> mymap;
long long compute(long long n){
	if(n==0)
		return 0;
	if(mymap[n]!=0)
		return mymap[n];
	long long temp1=floor(n/2);
	long long temp2=floor(n/3);
	long long temp3=floor(n/4);
	long long x=compute(temp1)+compute(temp2)+compute(temp3);
	if(x>n)
		mymap[n]=x;
	else 
		mymap[n]=n;
	return mymap[n];
}
int main(){
	long long n;
	string str;
	mymap[0]=0;
	while(getline(cin,str)){
		n=atoi(str.c_str());
		cout<<compute(n)<<endl;
	}
}