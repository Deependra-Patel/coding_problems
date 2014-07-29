#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <map>
using namespace std;
bool* arr=new bool[1000001];
vector<int> list_primes;

bool check_pr(long long x){
	if(x<=1000000)
		return arr[x];
	else{
		for(int i=0; i<list_primes.size(); i++){
			if(x%list_primes[i]==0)
				return false;
		}
		return true;
	}
}
int main(){
	int ntest;
	cin>>ntest;
	int num=1000001;
	for(int i=0; i<num; i++){
		arr[i]=true;
	}
	for(int i=2; i<1000001; i++){
		if(arr[i]){
			int index=2*i;
			while(index<num){
				arr[index]=false;
				index+=i;
			}
		}
	}
	arr[0]=false;
	arr[1]=false;
	for(int i=2; i<num; i++){
		if(arr[i]){
			list_primes.push_back(i);
		}
	}
/*	for(int i=1; i<100; i++)
		cout<<i<<"  "<<arr[i]<<endl;*/
	while(ntest--){
		long long n;
		cin>>n;
		n=n/2;
		vector<long long> ans;
		for(long long i=2; i<sqrt(n); i++){
			//cout<<i<<endl;
			if(n%i==0){
				if(!check_pr(i)){
					ans.push_back(i);
				}
				if(!check_pr(n/i))
					ans.push_back(n/i);
			}
		}
		if(n==sqrt(n)*sqrt(n)){
			if(!check_pr(sqrt(n)))
				ans.push_back(sqrt(n));
		}
		ans.push_back(1);
		if(!check_pr(n))
			ans.push_back(n);
		sort(ans.begin(), ans.end());
		cout<<ans.size()<<" ";
		for(int i=0; i<ans.size(); i++)
			cout<<ans[i]<<" ";
		cout<<endl;
	}
}