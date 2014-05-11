#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	int ntest;
	cin>>ntest;
	for(int i=0; i<ntest; i++){
		int n, m;
		scanf("%d %d",&n, &m);
		vector<int> vec(n);
		for(int j=0; j<n; j++)
		scanf("%d", &vec[j]);
		sort(vec.begin(), vec.end());
		int low=0, high=n-1, count=0;
		while(low<high){
			int temp=(vec[low]+vec[high]);
			if(temp==m){
				count++;
				low++;
				high--;
			}
			else if(temp>m)
			high--;
			else low++;
		}
		printf("%d \n",count);
	}
}
