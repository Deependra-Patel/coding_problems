#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	int n;
	cin>>n;
	while(n!=0){
		vector<long long int> p(n);
		vector<long long int> c(n);
		for(int i=0; i<n; i++)
		scanf("%d", &c[i]);
		for(int i=0; i<n; i++)
		scanf("%d", &p[i]);
		sort(p.begin(), p.end());
		sort(c.begin(), c.end());
		unsigned long long sum=0;
		for(int i=0; i<n; i++){
			sum+=p[i]*c[n-i-1];
		}
		cout<<sum<<endl;
		scanf("%d", &n);
	}
}
