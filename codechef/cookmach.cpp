#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

int getPow(int x){
	int cnt = 0;
	while(x>>1){
		cnt++;
		x = x>>1;
	}
	return cnt;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int a, b;
		cin>>a>>b;
		if(!(a&(a-1))){
			cout<<abs(getPow(a)-getPow(b))<<endl;
		}
		else {
			int cnt = 0;
			int temp = a;
			while(temp&(temp-1)){
				temp = temp>>1;
				cnt++;
			}
			cout<<cnt+abs(getPow(temp)-getPow(b))<<endl;			
		}
	}
}
