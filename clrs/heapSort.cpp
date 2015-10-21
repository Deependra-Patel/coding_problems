#include <iostream>
#include <vector>
using namespace std;
int curSize;
void insert(vector<int> &arr, int x){
	arr[curSize] = x;
	int parent = (curSize-1)/2;
	int child = curSize;
	while(parent<child && arr[parent]>arr[child]){
	    int temp = arr[parent];
		arr[parent] = arr[child];
		arr[child] = temp;
		child = parent;
		parent = parent/2;
	}
	curSize++;
}

void remove(vector<int> &arr, int index){
	arr[index] = arr[curSize-1];
	curSize --;	
	while(index<curSize){
		int child1 = 2*index+1;
		int child2 = 2*index+2;
		if(child1 >= curSize) break;
		else if(child2 >= curSize){
			if(arr[child1] < arr[index]){
				int temp = arr[index];
				arr[index] = arr[child1];
				arr[child1] = temp;
			}
			break;
		}
		else if(arr[index] > min(arr[child1], arr[child2])){
			if(arr[child1] < arr[child2]){
				int temp = arr[index];
				arr[index] = arr[child1];
				arr[child1] = temp;
				index = child1;
			}
			else {
				int temp = arr[index];
				arr[index] = arr[child2];
				arr[child2] = temp;
				index = child2;
			}
		}
		else break;
	}
}

int min(vector<int> &arr){
	if(curSize > 0)
		return arr[0];
	else return -1;
}

void printv(vector<int> &arr){
	for(int i=0; i<curSize; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	curSize = 0;
	for(int i=0; i<n; i++){
		int x;
		cin>>x;
		insert(arr, x);
		//cout<<"min "<<arr[0]<<endl;
		//printv(arr);
	}
	for(int i=0; i<n; i++){
		cout<<min(arr)<<endl;
		remove(arr, 0);
		//	printv(arr);
	}
}
