#include <iostream>
#include <math.h>
#include <vector>
#include <stdio.h>
using namespace std;

int main()
{
	int ntest;
	cin>>ntest;
	vector<int> primes;
	int li = (int)sqrt(1000000000);
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
	
	while(ntest--){
		int n, m;
		cin>>m>>n;
		/*bool* prime = new bool[n-m+1];
		for(int i=0; i<=n-m; i++)
			prime[i] = true;
		int temp = sqrt(n);
		for(int i=2; i<=temp; i++){
			int temp2 = (m/i)*i;
			if(m%i != 0)
				temp2 += i;
			while(temp2<=n){
				prime[temp2-m] = false;
				temp2+=i;
			}
		}
		for(int i=0; i<=n-m; i++){
			if(prime[i])
				cout<<i+m<<endl;
				}*/
		int size = primes.size();
		int i;
		if(m==1)
			m=2;
		
		for(i=m; i<=n; i++){
			int j;
			bool isP= true;
			for(j=0; j<size && primes[j]<i; j++){
				if(i%primes[j] == 0){
					isP = false;
					break;
				}
			}
			if(isP)
				printf("%d\n",i);
		}
		printf("\n");
	}
	
}
