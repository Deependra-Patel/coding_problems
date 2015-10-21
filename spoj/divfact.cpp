#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
#define mod 1000000007


int main(){
	int ntest;
	cin>>ntest;
	vector<int> primes;
	int li = 50000;
	bool* sieve = new bool[li];
	sieve[0] = false;
	for(int i=1; i<li; i++){
		sieve[i] = true;
	}
	for(int i=1; i<li; i++){
		if(sieve[i]){
			primes.push_back(i+1);
			int temp = 2*(i+1);
			while(temp<li){
				sieve[temp-1] = false;
				temp+=i+1;
			}
		}
	}
	int size = primes.size();
	//cout<<size<<endl;
	while(ntest--){
		int n;
		cin>>n;
		int* facCount = new int[size];
		for(int i=0; i<size; i++)
			facCount[i] = 0;
		for(int i=0; i<size;i++){
			int prime = primes[i];
			long long temp = prime;
			while(temp<=n){
				facCount[i] += n/temp;
				temp = temp*prime;
			}
		}
		long long ans = 1;
		for(int i=0; i<size; i++){
			ans = (ans*(facCount[i]+1))%mod;
		}
		cout<<ans<<endl;
	}
}
