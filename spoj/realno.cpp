#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	char ntest;
	scanf("%c", &ntest);
	for(char i='0'; i<ntest; i++){
		int n;
		scanf("%d",&n);
		float x,nearest0=2, f2=0, max1=0;
		bool flag=false;
		for(int j=0; j<n; j++){
			scanf("%f", &x);
			if(!flag){
				if(x>=1){
					if((x+nearest0)<2)
					flag=true;
				}
				else if(x<=0.5){
					if(x>max1){
						max1=x;
					}
					if(nearest0>x){
						nearest0=x;
					}
				}
				else {
					if(f2==1 || (x+max1>1))
					flag=true;
					else {
						f2++;
						if(nearest0>x)
						nearest0=x;
					}	
				}
			}
		}
		if(flag)
		printf("found \n");
		else 
		printf("not found \n");
	}
}
