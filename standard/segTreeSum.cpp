#include <iostream>
#include <math.h>
using namespace std;

int mid(int x, int y){return x+(y-x)/2;}
int fillSegTree(int* arr, int* st, int ss, int se, int index){
	if(ss == se){
		st[index] = arr[ss];
		return st[index];
	}
	int midi = mid(ss, se);
	st[index] = fillSegTree(arr, st, ss, midi, 2*index+1)+
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
	fillSegTree(arr, st, 0, n-1, 0);
	return st;
}

int sumQuery(int* st, int i, int j, int ss, int se, int index){
	if(i <= ss && se <= j)
		return st[index];
	else if(i > se || j < ss)
		return 0;
	else {
		int midi = mid(ss, se);
		return sumQuery(st, i, j, ss, midi, 2*index + 1)+
			sumQuery(st, i, j, midi+1, se, 2*index + 2);
	}
}

void updateQuery(int *st, int ss, int se, int index, int valInd, int val){
	if(ss == se && ss == valInd){
		st[index] = val;
	}
	else {
		int midi = mid(ss, se);
		if(valInd <= midi)
			updateQuery(st, ss, midi, 2*index+1, valInd, val);
		else updateQuery(st, midi+1, se, 2*index+2, valInd, val);
		st[index] = st[2*index+1]+st[2*index+2];
	}
}

int main(){
	int n;
	cin>>n;
	int* arr = new int[n];
	for(int i=0; i<n; i++)
		cin>>arr[i];
	int* st = createSegTree(arr, n);
	//printTree(st, n);
	int kc;
	cin>>kc;
	while(kc--){
		int type;
		cin>>type; //update/sum
		if(type == 0){ //update
			int valInd, val;
			cin>>valInd>>val;
			updateQuery(st, 0, n-1, 0, valInd-1, val);
		}
		else {
			int i, j;
			cin>>i>>j;
			cout<<sumQuery(st, i-1, j-1, 0, n-1, 0)<<endl;
		}
	}
}
