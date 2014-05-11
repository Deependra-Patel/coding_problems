#include <iostream>
using namespace std;
long long gcd(long long a, long long b){
	if(b==0)
	return a;
	else return gcd(b, a%b);
}

int main(){
	int ntest;
	cin>>ntest;
	for(int z=0; z<ntest; z++){
		long long n, i;
		cin>>n;
		i=n/2;
		if(n%2==0 && i%2==0){
		i--;
		for(; i>=1 ;i=i-2){
			if(gcd(n,i)==1){
				cout<<i<<endl;
				break;
			}
		}
		}
		else for(; i>=1 ;i=i--){
				if(gcd(n,i)==1){
					cout<<i<<endl;
					break;
				}
		}
	}
}
