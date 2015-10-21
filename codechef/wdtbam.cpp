#include <iostream>
using namespace std;
int main(){
	int ntest;
	cin>>ntest;
	while(ntest--){
		int n;
		cin>>n;
		string ans, chef;
		cin>>ans>>chef;
		int same = 0;
		for(int i=0; i<n; i++)
			if(ans[i] == chef[i])
				same++;
		
		int* cost = new int[n+1];
		int maxTill = -1;
		int full;
		for(int i=0; i<n+1; i++){
			int x;
			cin>>x;
			if(i == n)
				full = x;
			maxTill = max(maxTill, x);
			cost[i] = maxTill;
		}

		if(same == n){
			cout<<full<<endl;
		}
		else cout<<cost[same]<<endl;
	}
}
