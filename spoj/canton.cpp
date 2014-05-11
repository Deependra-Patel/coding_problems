#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	while(n--){
		int x;
		cin>>x;
		int level=0, sum=0;
		while(sum<x){
			level++;
			sum+=level;
		}
		sum=sum-level;
		level--;
		int mod=x-sum;
		cout<<"TERM "<<x<<" IS "; 
		if(level%2==0){
			cout<<level+2-mod<<"/"<<mod<<endl;
		}
		else 
			cout<<mod<<"/"<<level+2-mod<<endl;

	}
}
