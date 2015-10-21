#include <iostream>
#include <stdio.h>
using namespace std;


	
int maximumSubArrayNLogNHelper(int* arr, int start, int end){
	if(end<start){
		return  -1;
	}
	int mid = (start+end)/2;
	int left = maximumSubArrayNLogNHelper(arr, start, mid-1);		
	int right = maximumSubArrayNLogNHelper(arr, mid+1, end);
	int maxArr = 0;
	int maxLeft = 0, maxRight = 0;
	int leftSum = 0,  rightSum = 0;
	for(int i=mid-1; i>=start; i--){
		leftSum += arr[i];
		maxLeft = max(maxLeft, leftSum);		
	}
	for(int i=mid+1; i<=end; i++){
		rightSum += arr[i];
		maxRight = max(maxRight, rightSum);
	}
	maxArr = max(max(maxLeft+maxRight+arr[mid], left), right);
	return maxArr;
}

int maximumSubArrayNLogN(int* arr, int n){
	int root = maximumSubArrayNLogNHelper(arr, 0, n-1);
	return root;
}

struct mypair{
	int maxArr, contMax;
};
mypair maximumSubArrayN(int* arr, int n){
	if(n == 1){
		int maxArr=0, contMax = 0;
		if(arr[0]>0){
			maxArr = contMax = arr[0];
		}
		mypair ans;
		ans.maxArr = maxArr;
		ans.contMax = contMax;
		return ans;
	}
	mypair ahead = maximumSubArrayN(arr+1, n-1);
	mypair ans;
	ans.contMax = max(0, ahead.contMax + arr[0]);
	ans.maxArr = max(ahead.maxArr, ans.contMax);
	return ans;
}

int main(){
	int n;
	scanf("%d", &n);
	int* arr = new int[n];
	for(int i=0; i<n; i++){
		scanf("%d", arr+i);
	}
	cout<<"MaxSubArray Sum: "<<maximumSubArrayN(arr, n).maxArr<<endl;
}
