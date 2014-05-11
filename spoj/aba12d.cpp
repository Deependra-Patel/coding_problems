#include <iostream>
using namespace std;

int main(){
	char* arr=new char[1000000];
	long long* sum_div=new long long[1000000];
	for(int i=0; i<1000000; i++){
		arr[i]='p';
		sum_div[i]=1;
	}
	
	arr[0]='c';
	for(int i=1; i<1000000; i++){
		int diff=i+1, ind;

		if(arr[i]=='p'){
			sum_div[i]+=diff;
			ind=2*diff;
			while(ind<=1000000){
				sum_div[ind-1]+=diff;
				arr[ind-1]='c';
				ind+=diff;
			}
		}
		else {
			ind=i+1;
			while(ind<=1000000){
				sum_div[ind-1]+=diff;
				ind+=diff;
			}
		}
	}
	/*for(int i=0; i<10; i++){
		cout<<i+1<<" "<<sum_div[i]<<endl;
	}*/
	int ntest;
	cin>>ntest;
	for(int z=0; z<ntest; z++){
		int a, b;
		cin>>a>>b;
		int count=0;
		for(int i=a-1; i<=b-1; i++){
			if(arr[(sum_div[i])-1]=='p')
			count++;
		}
		cout<<count<<endl;
	}
}
