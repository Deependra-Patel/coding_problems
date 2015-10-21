#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
int sumdig(int n){
	int sum = 0;
	while(n){
		sum += n%10;
		n/=10;
	}
	return sum;
}

void printvec(vector<int> vec){
	for(int i=0; i<vec.size(); i++)
		cout<<vec[i]<<" ";
	cout<<endl;
}
int main(){
	int ntest;
	cin>>ntest;
	bool win[1000];
	for(int i=0; i<1000; i++) win[i] = false;

	win[0] = false;
	vector<int> primes;
	for(int i=2; i<=1000; i++){
		int j;
		for(j=2; j<i; j++){
			if(i%j == 0)
				break;
		}
		if(j == i)
			primes.push_back(i);
	}
	//printvec(primes);
	for(int i=2; i<=1000; i++){
		int s = sumdig(i);
		int willwin = false;
		bool cnt = false;
		for(int j=0; j<primes.size(); j++){
			if(s == primes[j] || s == 1){
				cnt = true;
				break;
			}
		}
		if(cnt) continue;
		//cout<<"i"<<i<<endl;
		for(int j=0; j<primes.size(); j++){
			int temp = i;
			int prime = primes[j];			
			if(i%prime == 0){
				//	cout<<prime<<endl;
				while(temp%prime == 0){
					temp/=prime;
				}
				//int x= sumdig(temp);
				if(!win[temp-1]){
					willwin = true;
					break;
				}					
			}
		}
		if(willwin){
			win[i-1] = true;
		}
	}
	
	for(int z=1; z<=ntest; z++){
		int n;
		cin>>n;
		if(!win[n-1])
			printf("Case #%d: Seymour\n", z);
		else printf("Case #%d: Laurence\n", z);
	}
}
