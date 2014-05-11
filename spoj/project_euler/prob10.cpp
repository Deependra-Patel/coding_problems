#include <iostream>
using namespace std;
void cross_comp(int arr[], int diff){
	int ind=2*diff;
	while(ind<=2000000){
		arr[ind-1]='c';
		ind+=diff;
	}
}
int main(){
	int* arr=new int[2000000];
	for(int i=0; i<2000000; i++){
		arr[i]='p';
	}
	long long sum=0;
	for(int i=1; i<2000000; i++){
		if(arr[i]=='p'){
			sum+=1+i;
			cross_comp(arr, i+1);
			if(sum>142915828922)
			cout<<"hm";
		}
	}
	for(int i=0; i<100; i++){
		cout<<i+1<<" "<<arr[i];
	}
	cout<<sum;
}
