#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binik_serach(vector<long long> vec, int left, int right, int n, int x){
	if(right<left)
		return -1;
	int mid=(left+right)/2;
	while(mid>=left){
		if(vec[mid]==x){
			return mid;
		}
		else if(vec[mid]<x){
			left=mid+1;
		}
		else right=mid-1;
	}
	return -1;
}

bool test(vector<long long> vec, int n, long long p){
			for(int i=0; i<n; i++){
			for(int j=i+1; j<n; j++){
					/*if(binik_search(vec.begin(),vec.begin()+i-1, p-vec[i]-vec[j]) || binik_search(vec.begin()+i,vec.begin()+i+j, p-vec[i]-vec[j]) || binik_search(vec.begin()+i+j,vec.end(), p-vec[i]-vec[j]))
						return true;*/
				}
			}
		return false;
}
int main(){
	int tests;
	cin>>tests;
	while(tests!=0){
		int n;
		cin>>n;
		vector<long long> vec(n);
		for(int i=0; i<n; i++){
			cin>>vec[i];
		}
		long long p;
		cin>>p;
		sort(vec.begin(), vec.end());
		cout<<binik_search(vec, 2, 5,n,4);
		if(test(vec, n, p))
		cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		tests--;
	}
}