#include <iostream>
using namespace std;
#include <iostream>
#include <math.h>
using namespace std;
int k;
int * maxi;
int* mini;
int x = 0;
int mid(int x, int y){return x+(y-x)/2;}
int fillSegTree(int* arr, int* st, int ss, int se, int index){
	if(ss == se){
		st[index] = 1;
		maxi[index] = mini[index] = arr[ss];
		return st[index];
	}
	int midi = mid(ss, se);
	st[index] = fillSegTree(arr, st, ss, midi, 2*index+1)+
		        fillSegTree(arr, st, midi+1, se, 2*index+2);
	maxi[index] = max(maxi[2*index+1], maxi[2*index+2]);
	mini[index] = min(mini[2*index+1], mini[2*index+2]);
	return st[index];
}

void printTree(int *st, int n){
	for(int i=0; i<2*pow(2, ceil(log2(n)))-1; i++)
		cout<<st[i]<<" "<<maxi[i]<<" "<<mini[i]<<endl;
	cout<<endl;
}

int* createSegTree(int* arr, int n){
	int size = 2*pow(2, ceil(log2(n))) - 1;
	int * st = new int[size];
	maxi = new int[size];
	mini = new int[size];
	fillSegTree(arr, st, 0, n-1, 0);
	return st;
}

int sumQuery(int* st, int i, int j, int ss, int se, int index){
	//	x++;
	//cout<<ss<<" "<<se<<" "<<index<<endl;
	int midi = mid(ss, se);
	if(i > se || j < ss)
		return 0;
	else if(mini[index]>k && se<=j && ss>=i)
		return st[index];
	else if(mini[index]>k && se>j)
		return st[index] - (se-j);
	else if(mini[index]>k && ss<i)
		return st[index]-(i-ss);
	else if(maxi[index]<=k)
		return 0;
	else 
		return sumQuery(st, i, j, ss, midi, 2*index + 1)+
			sumQuery(st, i, j, midi+1, se, 2*index + 2);
}

int main(){
	int n;
	cin>>n;
	int* arr = new int[n];
	for(int i=0; i<n; i++)
		cin>>arr[i];
	int* num = createSegTree(arr, n);
	//printTree(num, n);
	int kc;
	cin>>kc;
	k = 1;
	//cout<<"ddd "<<sumQuery(num, 2, 4, 3, 4, 2)<<endl;
	while(kc--){
		int i, j;
		cin>>i>>j>>k;
		cout<<sumQuery(num, i-1, j-1, 0, n-1, 0)<<endl;
		//cout<<x<<endl;
	}
}
