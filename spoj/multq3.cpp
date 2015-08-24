#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
int* rem1;
int* rem2;
int* curState;

int cnt = 0;
inline int mid(int x, int y){return (x+y)>>1;}
int trMat[3][3] = {{0,1,2},{2,0,1},{1,2,0}};
int fillSegTree(int* arr, int* st, int ss, int se, int index){
	if(ss == se){
		st[index] = 1;
		return 1;
	}
	int midi = mid(ss, se);
	st[index] = fillSegTree(arr, st, ss, midi, index<<1|1)+
		        fillSegTree(arr, st, midi+1, se, 2*index+2);
	return st[index];
}

void printTree(int *st, int n){
	for(int i=0; i<2*pow(2, ceil(log2(n)))-1; i++)
		cout<<st[i]<<" ";
	cout<<endl;
}

int* createSegTree(int* arr, int n){
	int size = 2*pow(2, ceil(log2(n))) - 1;
	int * st = new int[size];
	rem1 = new int[size];
	rem2 = new int[size];
	curState = new int[size];
	fillSegTree(arr, st, 0, n-1, 0);
	return st;
}

int sumQuery(int* st, int i, int j, int ss, int se, int index, int rem){
	//	int fRem =(abs(curState[index]-rem))%3;
	int fRem = trMat[curState[index]][rem];
	if(i <= ss && se <= j){
		if(rem == 0)
			return st[index];
		else if(rem == 1)
			return rem1[index];
		else return rem2[index];
	}
	else if(j<ss || i>se)
		return 0;
	else {
		int midi = mid(ss, se);
		if(j<=midi)
			return sumQuery(st, i, j, ss, midi, index<<1|1, fRem);
		else if(i>midi)
			return sumQuery(st, i, j, midi+1, se, 2*index+2, fRem);
		else return sumQuery(st, i, j, ss, midi, index<<1|1, fRem)+
			sumQuery(st, i, j, midi+1, se, 2*index + 2, fRem);
	}
}
void cycle(int *st, int index){
	int temp = st[index];
	st[index] = rem2[index];
	rem2[index] = rem1[index];
	rem1[index] = temp;
}

void updateQuery(int *st, int ss, int se, int index, int a, int b){
	if(ss >= a && se <= b){
		cycle(st, index);
		curState[index] = (curState[index]+1)%3;
	}
	else {
		int i1, i2;
		i1 = index<<1|1;
		i2 = i1+1;
		int midi = mid(ss, se);
		if(b <= midi)
			updateQuery(st, ss, midi, i1, a, b);
		else if(a > midi)
			updateQuery(st, midi+1, se, i2, a, b);
		else {
			updateQuery(st, ss, midi, i1, a, b);			
			updateQuery(st, midi+1, se, i2, a, b);
		}
		if(curState[index] == 0){
			st[index] = st[i1]+st[i2];
			rem1[index] = rem1[i1]+rem1[i2];
			rem2[index] = rem2[i1]+rem2[i2];
		}
		else if(curState[index] == 1){
			rem1[index] = st[i1]+st[i2];
			rem2[index] = rem1[i1]+rem1[i2];
			st[index] = rem2[i1]+rem2[i2];
		}
		else {
			rem2[index] = st[i1]+st[i2];
			st[index] = rem1[i1]+rem1[i2];
			rem1[index] = rem2[i1]+rem2[i2];
		}
		//	for(int i=0; i<curState[index]; i++)
		//	cycle(st, index);
	}
}

int readInt () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}
int main(){
	int n;
	cin>>n;
	int * arr;
	int* st = createSegTree(arr, n);
	//printTree(st, n);
	int kc;
	cin>>kc;
	while(kc--){
		int type;
		cin>>type; //update/sum
		if(type == 0){ //update
			int a, b;
			//a = readInt();
			//b = readInt();
		  	scanf("%d%d", &a, &b);
			updateQuery(st, 0, n-1, 0, a, b);
		}
		else {
			int i, j;
			//cin>>i>>j;
			scanf("%d%d", &i, &j);
			//i = readInt();
			//j = readInt();
			printf("%d\n",sumQuery(st, i, j, 0, n-1, 0, 0));
			//cout<<cnt;
		}
		/*printTree(curState, n);
		printTree(st, n);
		printTree(rem1, n);
		printTree(rem2, n);
		cout<<"done"<<endl;*/
	}
}
