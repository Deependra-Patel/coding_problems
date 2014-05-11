#include <iostream>
using namespace std;
long long gcd(long long a, long long b){
	if(b==0)
	return a;
	else return gcd(b, a%b);
}

int main(){
	bool* arr=new bool[1034568];
	
	for(int i=2; i<1034568; i++)
	arr[i]=true;
	
	for(int i=2; i<1034568; i++){
		if(arr[i]){
			int temp=i, factor=2;
			temp=factor*i;
			while(temp<1034568){
				arr[temp]=false;
				factor++;
				temp=i*factor;
			}
		}
	}

	int count=0;
	for(int i=2; i<1034568; i++){
		int gc=gcd(1034568, i);
		if(!arr[gc])
		count++;
	}
	cout<<count;
}
