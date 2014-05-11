#include <iostream>
using namespace std;
int main(){
	int fact[10];
	fact[0]=1;
	for(int i=1; i<=9; i++){
		fact[i]=i*fact[i-1];
		cout<<fact[i]<<endl;
	}
	long long sum=0;
	for(int i=10; i<1000000; i++){
			int tep=i;
			int su=0;
			while(tep>0){
				su+=fact[tep%10];
				tep/=10;
			}
			if(su==i){
			sum+=i;
			cout<<i<<endl;}
	}
	cout<<sum;
}
