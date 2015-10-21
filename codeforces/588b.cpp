#include <iostream>
#include <vector>
#include <math.h>
using namespace  std;
int main(){
	long long n;
	cin>>n;
	long long sq = sqrt(n);
	bool* sieve = new bool[sq];
	for(int i=0; i<sq; i++) sieve[i] = true;
	long long ans = 1;
	for(long long i=2; i<=sq; i++){
		if(!sieve[i-1])
			continue;
		while(n%(i*i) == 0){
			n /= i;
		}
		//sieve[i-1] = ;
		long long temp = 2*i;		
		while(temp<=sq){
			sieve[temp-1] = false;
			temp += i;
		}		
	}
	//for(long long i=2; i<=sq; i++)if(sieve[i-1])cout<<i<<endl;
	cout<<n<<endl;
}
