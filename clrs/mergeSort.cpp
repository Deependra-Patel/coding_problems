#include <iostream>
using namespace std;

void mergeSortHelper(int* arr, int n,  int* helper){
	if(n == 1)
		return;
	mergeSortHelper(arr, n/2, helper);
	mergeSortHelper(arr+n/2, n-n/2, helper);
	int ind1 = 0;
	int ind2 = n/2;
	while(ind1 < n/2 && ind2 < n){
		if(arr[ind1] < arr[ind2]){
			helper[ind1+ind2-n/2] = arr[ind1];
			ind1++;
		}
		else {
			helper[ind1+ind2-n/2] = arr[ind2];
			ind2++;
		}
	}
	while(ind1<n/2){
		helper[ind1+ind2-n/2] = arr[ind1];
		ind1++;
	}
	while(ind2<n){
		helper[ind1+ind2-n/2] = arr[ind2];
		ind2++;
	}
	for(int i=0; i<n; i++)
		arr[i] = helper[i];
}

int countInversions(int* arr, int n,  int* helper){
	if(n == 1)
		return 0;
	int count = 0;
	count += countInversions(arr, n/2, helper);
	count += countInversions(arr+n/2, n-n/2, helper);
	int ind1 = 0;
	int ind2 = n/2;
	//	cout<<arr[0]<<endl;
	while(ind1 < n/2 && ind2 < n){
		if(arr[ind1] < arr[ind2]){
			helper[ind1+ind2-n/2] = arr[ind1];
			ind1++;
		}
		else {
			helper[ind1+ind2-n/2] = arr[ind2];
			ind2++;
			//		cout<<"here"<<endl;
			count += n/2-ind1;
		}
	}
	while(ind1<n/2){
		helper[ind1+ind2-n/2] = arr[ind1];
		ind1++;
		//	count += n-n/2;
	}
	while(ind2<n){
		helper[ind1+ind2-n/2] = arr[ind2];
		ind2++;
	}
	for(int i=0; i<n; i++)
		arr[i] = helper[i];
	return count;
}

void mergeSort(int* arr, int n){
	int* helper = new int[n];
	mergeSortHelper(arr, n, helper);	
}

int  binarySearch(int* arr, int size, int x){
	if(size == 0)
		return -1;
	int mid = size/2;
	if(arr[mid] == x)
		return mid;
	else if(arr[mid] < x){
		int ind = binarySearch(arr+mid+1, size-mid-1, x);
		if(ind == -1)
			return -1;
		else return mid+ind+1;
	}
	else {
		int ind = binarySearch(arr, mid, x);
		if(ind == -1)
			return -1;
		else return ind;
	}
}

int binarySearch(int* arr, int left, int right, int x){
	if(right>=left){
		int mid = (right+left)/2;
		if(arr[mid] == x)
			return mid;
		else if(arr[mid]<x){
			return binarySearch(arr, mid+1, right, x);
		}
		else return binarySearch(arr, left, mid-1, x);
	}
	else return -1;
}

int main(){
	int n;
	cin>>n;
	int* a = new int[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	int * temp = new int[n];
	cout<<"Inversions: "<<countInversions(a, n, temp)<<endl;
	
	mergeSort(a, n);
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
	int x;
	cin>>x;
	while(x!=-1){
		cout<<binarySearch(a, 0, n-1, x)<<endl;
		cin>>x;
	}
}
