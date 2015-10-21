#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

bool checkP(int n){
	for(int i=2; i<=sqrt(n); i++){
		if(n%i == 0)
			return false;
	}
	return true;
}
int main(){
	int n;
	cin>>n;
	vector<int> primes;
	for(int i=2; i<=n; i++){
		if(checkP(i))
			primes.push_back(i);
	}
	vector<int> ans;
	for(int i=0; i<primes.size(); i++){
		int temp = primes[i];
		while(temp<=n){
			ans.push_back(temp);
			temp *= primes[i];
		}
	}
	cout<<ans.size()<<endl;
	for(int i=0; i<ans.size(); i++)
		cout<<ans[i]<<" ";
	cout<<endl;
}
