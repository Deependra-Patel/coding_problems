#include <iostream>
#include <map>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	int ntest;
	cin>>ntest;
	for(int z=0; z<ntest; z++){
		int n,a,b,c;
		scanf("%d %d %d %d",&a,&b,&c,&n);
		map<long long, long long> ordered_by_val;
		ordered_by_val.insert(make_pair(1,1));
		map<long long, long long>::iterator it=ordered_by_val.begin();
		long long sum=1;
		int median=1;
		for(int i=2; i<=n; i++){
			median=(*it).second;
			int temp=(a*median + b*i + c)%1000000007;
			sum+=temp;
			ordered_by_val.insert(make_pair(i, temp));
			if(temp>median && (i%2==0))
			it++;
			else 
		}
		if(n==0)
		cout<<0<<endl;
		else
		cout<<sum<<endl;
	}
}
