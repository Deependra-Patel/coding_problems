#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> vote;
	int g;
	cin>>g;
	for(int i=0; i<n-1 ; i++){
		int t;
		cin>>t;
		vote.push_back(t);
	}
	sort(vote.begin(), vote.end());
	int cnt = 0;
	while(vote[n-2]>=g){
		vote[n-2] -= 1;
		g++;
		cnt++;
		sort(vote.begin(), vote.end());
	}
	cout<<cnt<<endl;
}
