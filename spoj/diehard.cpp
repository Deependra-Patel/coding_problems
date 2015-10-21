#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int dimensions[1003][2000][3];

int changeH[3] = {3, -5, -20};
int changeA[3] = {2, -10, 5};
int other[3][2] = {{1,2}, {2,0}, {0,1}};
int maxT(int h, int a, int cur){
	if(h<=0 || a<=0)
		return 0;
	if(dimensions[h-1][a-1][cur] != -1)
		return (dimensions[h-1][a-1][cur]);
	
	int temp = max(maxT(h+changeH[other[cur][0]], a+changeA[other[cur][0]], other[cur][0]),
				   maxT(h+changeH[other[cur][1]], a+changeA[other[cur][1]], other[cur][1]))+1;
	//cout<<h<<" "<<a<<endl;
	dimensions[h-1][a-1][cur] = temp;
	return temp;
}

int main(){
	int nt;
	cin >> nt;
	for(int i=0; i<1003; i++){
		for(int j=0; j<2000; j++)
			dimensions[i][j][0] = dimensions[i][j][1] = dimensions[i][j][2] = -1;
	}
	while(nt--){
		int h, a;
		cin>>h>>a;
		cout<<max(maxT(h-5, a-10, 1), max(maxT(h+3, a+2, 0), maxT(h-20, a+5, 2)))<<endl;
		/*for(int i=0; i<21; i++){
			for(int j=0; j<20; j++){
				for(int k=0; k<3; k++)
					cout<<dimensions[i][j][k]<<" ";
				cout<<endl;
			}
			}*/
	}
}
/*
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
*/
