#include <iostream>
using namespace std;
int **winBy;
int *arr;
int calc(int i, int j){
	if(winBy[i][j]!= -1)
		return winBy[i][j];
	if(i == j)
		return arr[i];
	if(i+1 == j){
		winBy[i][j]=max(arr[i], arr[j])-min(arr[i], arr[j]);
		return winBy[i][j];
	}
	int first, last;
	if(arr[i+1]<arr[j])
		first = calc(i+1, j-1)+arr[i]-arr[j];
	else first = calc(i+2, j)+arr[i]-arr[i+1];
	if(arr[i]<arr[j-1])
		last = calc(i, j-2)+arr[j]-arr[j-1];
	else last = calc(i+1, j-1)+arr[j]-arr[i];
	int val = max(first, last);
	winBy[i][j] = val;
	return val;
}

int main(){
	int n;
	cin>>n;
	int ind = 1;
	while(n){
		arr = new int[n];
		for(int i=0; i<n; i++)
			cin>>arr[i];
		winBy = new int*[n];
		for(int i=0; i<n; i++){
			winBy[i] = new int[n];
			for(int j=0; j<n; j++)
				winBy[i][j] = -1;
		}			
		cout<<"In game "<<ind<<", the greedy strategy might lose by as many as "<<calc(0, n-1)<<" points."<<endl;
		ind++;
		cin>>n;
	}
}
