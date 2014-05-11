#include <iostream>
using namespace std;

#define size 1000000000
int main(){
	int ntest;
	cin>>ntest;
	bool* primes=new bool[size];
	for(int i=0; i<size; i++){
		primes[i]=true;
	}
	primes[0]=false;
	for(int i=1; i<size; i++){
		if(primes[i]){
			int index=2*i+1;
			while(index<size){
				primes[index]=false;
				index+=i+1;
			}
		}
	}
	
	while(ntest--){
		int n;
		cin>>n;
		int* arr=new int[n];
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}
		
	}
}
