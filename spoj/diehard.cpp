#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef int dimensions[1000][3];

int live(int h, int a, int state,dimensions arr[]){
	if(h<=0 || a<=0)
	return 0;
	else if(arr[h-1][a-1][state]!=-1)
	return arr[h-1][a-1][state];
	else {
		int x;
		if(state==0)
		x=1+max(live(h-5, a-10,1, arr), live(h+3, a+2,2, arr));
		else if(state==1)
		x=1+max(live(h-20, a+5,0, arr), live(h+3, a+2,2, arr));
		else x=1+max(live(h-5, a-10,1, arr), live(h-20, a+5,0, arr));
		arr[h-1][a-1][state]=x;
		return x;
	}
}
int main(){
	int ntest;
	cin>>ntest;
	dimensions * arr = new dimensions[1000];
	for(int i=0; i<1000; i++){
		for(int j=0; j<1000; j++){
			for(int k=0; k<3; k++)
			arr[i][j][k]=-1;
		}
	}
	for(int i=0; i<ntest; i++){
		int h, a;
		scanf("%d %d",&h, &a);
		if(h<=0 || a<=0)
		printf("0 \n");
		else {
		int count=max(live(h-1,a-1,0,arr),max(live(h-1,a-1,1,arr), live(h-1,a-1,2,arr)));
		printf("%d \n",count-1);
		}
	}
}
