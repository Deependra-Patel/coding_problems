#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
using namespace std;
 
int rem = 1000000007;
int CeilIndex(int A[], int l, int r, int key) {
    int m;
 
    while( r - l > 1 ) {
        m = l + (r - l)/2;
        (A[m] >= key ? r : l) = m; // ternary expression returns an l-value
    }
 
    return r;
}
 
int LongestIncreasingSubsequenceLength(int A[], int size) {
    // Add boundary case, when array size is one
 
    int *tailTable   = new int[size];
    int len; // always points empty slot
 
    memset(tailTable, 0, sizeof(tailTable[0])*size);
 
    tailTable[0] = A[0];
    len = 1;
    for( int i = 1; i < size; i++ ) {
        if( A[i] < tailTable[0] )
            // new smallest value
            tailTable[0] = A[i];
        else if( A[i] > tailTable[len-1] )
            // A[i] wants to extend largest subsequence
            tailTable[len++] = A[i];
        else
            tailTable[CeilIndex(tailTable, -1, len-1, A[i])] = A[i];
    }
 
    delete[] tailTable;
 
    return len;
}

vector<int> calc(int* arr, int k, int n){
	if(n == 1){
		vector<int> temp;
		temp.push_back(1);
		return temp;
	}
	int mid = n/2;
	if(n%2 == 0){
		//	if(mid < k && n-mid<k){
		vector<int> first = calc(arr, mid, mid);
		vector<int> second = calc(arr+mid, mid, n-mid);
		for(int i=0; i<mid; i++){
			
		}
	}
	else {

	}	
}

int main() {
    int ntest;
	cin>>ntest;
	while(ntest--){
		int n;
		cin>>n;
		int* arr = new int[n];
		for(int i=0; i<n; i++) cin>>arr[i];
		int l = LongestIncreasingSubsequenceLength(arr, n)-1;
		cout<<calc(arr, l-1, n)[l-2]<<endl;
	}
    return 0;
}
