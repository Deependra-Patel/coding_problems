#include <iostream>
#include <vector>
using namespace  std;

int main(){
	int n;
	cin>>n;
	vector<long long> v, d, p;
	int* done = new int[n];
	for(int i=0; i<n; i++){
		done[i] = 0;
		int vi, di, pi;
		cin>>vi>>di>>pi;
		v.push_back(vi);
		d.push_back(di);
		p.push_back(pi);
	}
	int cnt = 0;
	int cur = 0;
	while(cur<n){
		if(done[cur]){
			cur++;		
			continue;
		}
		done[cur] = 2;
		cnt++;
		long long sub = v[cur];
		long long sub2 = 0;
		for(int i=cur+1; i<n; i++){
			if(done[i])
				continue;
			p[i] -= sub+sub2;
			if(sub>0)
				sub--;
			if(p[i]<0){
				done[i] = 1;
				sub2 += d[i];
			}
		}
		cur++;
	}
	cout<<cnt<<endl;
	for(int i=0; i<n; i++){
		if(done[i] == 2)
			cout<<i+1<<" "; 
	}
	cout<<endl;
}
