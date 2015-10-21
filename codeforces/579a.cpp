#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	int x;
	cin>>x;
	int sum = 0;
	while(x!=0){
		if(x&1)
			sum++;
		x = x>>1;
	}
	cout<<sum<<endl;
}
