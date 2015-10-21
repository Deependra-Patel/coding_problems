#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
#define mod 1000000007


int main(){
	int ntest;
	cin>>ntest;
	vector<long long> primes;
	int li = 1000000;
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
	long long size = primes.size();
	//	cout<<size<<endl;
	while(ntest--){
		long long  n;
		cin>>n;
		n = n/2;
		vector<long long> ans;
		ans.push_back(1);
		if(!sieve[n-1])
			ans.push_back(n);
		for(long long i=0; i<size;i++){
			long long  prime = primes[i];
			if(prime>=n)
				break;
			long long temp = prime;
			while(n%temp==0){
				if(!sieve[n/temp-1]){
					ans.push_back(n/temp);
					temp = temp*prime;
				}
				else break;
			}
		}
		sort(ans.begin(), ans.end());
		cout<<ans.size()<<" ";
		for(int i=0; i<ans.size(); i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
}
